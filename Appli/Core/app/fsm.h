#ifndef _FSM_H_
#define _FSM_H_

#include "main.h"
enum state {
    STATE_UNKNOWN,
    STATE_SLEEPING,
    STATE_IDLE,
    STATE_PROCESSING,
    STATE_ERROR
};

enum event {
    EVENT_INIT,   // first time init after power-up
    EVENT_SLEEP, // go to sleep
    EVENT_WAKEUP,  // called after wake up from low-power state
    EVENT_START,  // called to start processing
    EVENT_STEP,   // optional - performe one operation step
    EVENT_ERROR_OCCURED, // error. stop.
    EVENT_RESET   // go to uninitialized, restart from 0
};

typedef struct _fsm_t {
    enum state current_state;

    void (*new_state)(struct _fsm_t * self, enum state new_state);
    void (*on_event)(struct _fsm_t * self, int event);
} fsm_t; 


/** the default state change function */
extern void fsm_new_state(fsm_t * self, enum state new_state);

extern void init_fsm(fsm_t * fsm,
              enum state initial_state,
              void (*on_event)(fsm_t * self, int event),
              void (*new_state)(fsm_t * self, enum state new_state)
            );

#define FSM_NEW_STATE(fsm, state) \
    do { \
        if ((fsm)->new_state) { \
            (fsm)->new_state((fsm), (state)); \
        } \
    } while(0)

#endif /* _FSM_H_ */