#include <stdio.h>

#include "camera_subsys.h"
#include "fsm.h"


static fsm_t camera_fsm;

void cam_init()
{
    printf("Camera subsystem initialized\n");
    FSM_NEW_STATE(&camera_fsm, STATE_IDLE);
}
void cam_wakeup()
{
    printf("Camera subsystem wakeup executed\n");
}
void cam_tosleep()
{
    printf("Camera subsystem to sleep executed\n");
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

        default:
            printf("ERROR: Unknown event %d in camera_fsm\n", event);
            self->new_state(self, STATE_ERROR);
    }
}

void camera_init()
{
    init_fsm(&camera_fsm,STATE_UNKNOWN, camera_event, &fsm_new_state);

}
