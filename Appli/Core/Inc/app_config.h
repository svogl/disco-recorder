#ifndef _APP_CONFIG_H_
#define _APP_CONFIG_H_


#define VENC_WIDTH   800
#define VENC_HEIGHT  480

#define FRAMERATE    30

/* image formats to use: */
#define IMG_FMT_LCD 1
#define IMG_FMT_YUV  2
#define IMG_FMT IMG_FMT_LCD

#if IMG_FMT == IMG_FMT_LCD
#define VENC_PREPROC_FMT H264ENC_RGB565
#define DCMIPP_PIPE1_OUT_FMT DCMIPP_PIXEL_PACKER_FORMAT_RGB565_1
#endif

#if IMG_FMT == IMG_FMT_YUV
#define VENC_PREPROC_FMT H264ENC_YUV422_INTERLEAVED_YUYV
#define DCMIPP_PIPE1_OUT_FMT DCMIPP_PIXEL_PACKER_FORMAT_YUV422_1
#endif

///// app_camerapipeline config /////
#define USE_DCACHE

/*Defines: CMW_MIRRORFLIP_NONE; CMW_MIRRORFLIP_FLIP; CMW_MIRRORFLIP_MIRROR; CMW_MIRRORFLIP_FLIP_MIRROR;*/
#define CAMERA_FLIP CMW_MIRRORFLIP_NONE

#define ASPECT_RATIO_CROP       (1) /* Crop both pipes to nn input aspect ratio; Original aspect ratio kept */
#define ASPECT_RATIO_FIT        (2) /* Resize both pipe to NN input aspect ratio; Original aspect ratio not kept */
#define ASPECT_RATIO_FULLSCREEN (3) /* Resize camera image to NN input size and display a maximized image. See Doc/Build-Options.md#aspect-ratio-mode */
#define ASPECT_RATIO_MODE ASPECT_RATIO_CROP


#define NN_WIDTH      (480)
#define NN_HEIGHT     (480)
#define NN_BPP 3

#define COLOR_BGR (0)
#define COLOR_RGB (1)
#define COLOR_MODE    COLOR_RGB

#define CAM_WIDTH 640
#define CAM_HEIGHT 480

#endif
