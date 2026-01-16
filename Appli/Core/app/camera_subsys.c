#include <stdint.h>
#include <stdio.h>

#include "app_config.h"

#include "camera_subsys.h"
#include "fsm.h"
#include "app_camerapipeline.h"
#include "cmw_camera.h"


int32_t cameraFrameReceived=0;

static fsm_t camera_fsm;

uint32_t cam_buffer[CAM_WIDTH * CAM_HEIGHT * NN_BPP / 4];

void cam_init()
{
    printf("Camera subsystem initialized\n");
    FSM_NEW_STATE(&camera_fsm, STATE_IDLE);
    int pitch_nn = 0;
    uint32_t widths[2] = { CAM_WIDTH, CAM_WIDTH };
    uint32_t heights[2] = { CAM_HEIGHT, CAM_HEIGHT };      

    CameraPipeline_Init(widths, heights, &pitch_nn);
}

void cam_wakeup()
{
    printf("Camera subsystem wakeup executed\n");
    FSM_NEW_STATE(&camera_fsm, STATE_PROCESSING);
    /* Start LCD Display camera pipe stream */
    CameraPipeline_DisplayPipe_Start(cam_buffer, CMW_MODE_CONTINUOUS);
}
void cam_tosleep()
{
    printf("Camera subsystem to sleep executed\n");
    FSM_NEW_STATE(&camera_fsm, STATE_SLEEPING);
    CameraPipeline_DisplayPipe_Stop();
}

void cam_step()
{
    printf("Camera subsystem step executed\n");
}





/** FSM implementation:  */

void camera_event(fsm_t * self, int event) {
    switch (event) {
        case EVENT_INIT:
            cam_init();
            break;
        case EVENT_WAKEUP:
            cam_wakeup();
            break;
        default:   
            printf("ERROR: Unknown event %d in camera_fsm\n", event);
            self->new_state(self, STATE_ERROR);
    }
}

void camera_init()
{
    init_fsm(&camera_fsm,STATE_UNKNOWN, camera_event, &fsm_new_state);

}
