/** application side video encoder stuff */
#include "main.h"
#include "app_config.h"

#include "venc_interface.h"

#include "ewl.h"
#include "h264encapi.h"
#include "stm32n6xx_hal.h"
#include <stdint.h>

#define VIDEO_FRAME_NB 10

/* Private macro -------------------------------------------------------------*/

/* enable trace if possible */
#if USE_COM_LOG || defined(TERMINAL_IO)
#define TRACE_MAIN(...) printf(__VA_ARGS__)
#else
#define TRACE_MAIN(...)
#endif /* USE_COM_LOG || defined(TERMINAL_IO) */

/* Private variables ---------------------------------------------------------*/

uint16_t * pipe_buffer[2];
volatile uint8_t buf_index_changed = 0;
H264EncIn encIn= {0};
H264EncOut encOut= {0};
H264EncInst encoder= {0};
H264EncConfig cfg= {0};
uint32_t output_size = 0;
//uint32_t img_addr = 0;

static int frame_nb = 0;

// EWLLinearMem_t outbuf;

// __attribute__ ((section (".psram_bss")))
// __attribute__ ((aligned (32)))
// uint32_t vin_buffer[800*480];

// __attribute__ ((section (".psram_bss")))
// __attribute__ ((aligned (32)))
// uint32_t output_buffer[800*480];



int encoder_prepare(uint32_t width, uint32_t height, uint32_t * output_buffer)
{
  H264EncRet ret;

  H264EncPreProcessingCfg preproc_cfg = {0};

  /* software workaround for Linemult triggering VENC interrupt. Make it happen as little as possible */
  MODIFY_REG(DCMIPP->P1PPCR, DCMIPP_P1PPCR_LINEMULT_Msk,DCMIPP_MULTILINE_128_LINES);

  frame_nb = 0;
  /* Step 1: Initialize an encoder instance */
  /* set config to 1 ref frame */
  cfg.refFrameAmount = 1;
  /* 30 fps frame rate */
  cfg.frameRateDenom = 1;
  cfg.frameRateNum = FRAMERATE;
  /* Image resolution */
  cfg.width = width;
  cfg.height = height;
  /* Stream type */
  cfg.streamType = H264ENC_BYTE_STREAM;

  /* encoding level*/
  /*See API guide for level depending on resolution and framerate*/
  cfg.level = H264ENC_LEVEL_2_2;
  cfg.svctLevel = 0;

  /* Output buffer size */
//   outbuf.size = cfg.width * cfg.height;

  ret = H264EncInit(&cfg, &encoder);
  if (ret != H264ENC_OK)
  {
    TRACE_MAIN("error initializing encoder %d\n", ret);
    return -1;
  }

  /* set format conversion for preprocessing */
  ret = H264EncGetPreProcessing(encoder, &preproc_cfg);
  if(ret != H264ENC_OK){
    TRACE_MAIN("error getting preproc data\n");
    return -1;
  }
  preproc_cfg.inputType = VENC_PREPROC_FMT; // orig: H264ENC_RGB565;
  ret = H264EncSetPreProcessing(encoder, &preproc_cfg);
  if(ret != H264ENC_OK){
    TRACE_MAIN("error setting preproc data\n");
    return -1;
  }

  /*assign buffers to input structure */
  encIn.pOutBuf = output_buffer;
  encIn.busOutBuf = (uint32_t) output_buffer;
  encIn.outBufSize = width * height;

  /* create stream */
  ret = H264EncStrmStart(encoder, &encIn, &encOut);
  if (ret != H264ENC_OK)
  {
    TRACE_MAIN("error starting stream\n");
    return -1;
  }

  /* save the stream header */
  if (save_stream(encIn.pOutBuf,  encOut.streamSize))
  {
    TRACE_MAIN("error saving stream\n");
//    return -1;
  }
  TRACE_MAIN("stream started. saved %d bytes\n", encOut.streamSize);
  output_size+= encOut.streamSize;
  return 0;
}


int encode_frame(void* img_addr){
  TRACE_MAIN("-------- ENC START!\n");


  int ret = H264ENC_FRAME_READY;
  if(!img_addr){
    TRACE_MAIN("Error : NULL image address");
    return -1;
  }
  // every xth frame Intra
  if (! (frame_nb & 0x07))
  {
    /* if frame is the first : set as intra coded */
    encIn.timeIncrement = 0;
    encIn.codingType = H264ENC_INTRA_FRAME;
  }
  else
  {
    /* if there was a frame previously, set as predicted */
    encIn.timeIncrement = 1;
    encIn.codingType = H264ENC_PREDICTED_FRAME;
  }
  encIn.ipf = H264ENC_REFERENCE_AND_REFRESH;
  encIn.ltrf = H264ENC_REFERENCE;
  /* set input buffers to structures */
  encIn.busLuma = (uint32_t)img_addr;
  ret = H264EncStrmEncode(encoder, &encIn, &encOut, NULL, NULL, NULL);
  switch (ret)
  {
  case H264ENC_FRAME_READY:
    /*save stream */
    if (save_stream(encIn.pOutBuf,  encOut.streamSize))
    {
      TRACE_MAIN("error saving stream frame %d\n", frame_nb);
      return -1;
    }
    output_size += encOut.streamSize;
    break;
  case H264ENC_SYSTEM_ERROR:
    TRACE_MAIN("fatal error while encoding\n");
    break;
  default:
    TRACE_MAIN("error encoding frame %d : %d\n", frame_nb, ret);
    break;
  }
  frame_nb++;
  return 0;
}


int encoder_end(void){
  int ret = H264EncStrmEnd(encoder, &encIn, &encOut);
  TRACE_MAIN("done encoding %d frames. size : %d\n",frame_nb ,output_size);
  if (ret != H264ENC_OK)
  {
    return -1;
  }
  else
  {
    /* save stream tail */
    if (save_stream(encIn.pOutBuf,  encOut.streamSize))
    {
      TRACE_MAIN("error saving stream\n");
      return -1;
    }
    output_size+=encOut.streamSize;
  }

  return 0;
}


