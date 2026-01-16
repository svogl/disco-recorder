#ifndef _APP_VIDEO_H_
#define _APP_VIDEO_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>

#include "sd_interface.h"

/* Exported functions ------------------------------------------------------- */
int encoder_prepare(uint32_t width, uint32_t height, uint32_t * output_buffer);
int encode_frame(void* img_addr);
int encoder_end(void);

#endif /* _APP_VIDEO_H_ */
