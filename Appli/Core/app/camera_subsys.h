#ifndef _CAMERA_SUBSYS_H_
#define _CAMERA_SUBSYS_H_

#include "fsm.h"

extern void camera_init();

extern fsm_t* camera_fsm();


extern int32_t cameraFrameReceived; ///< counter
#endif