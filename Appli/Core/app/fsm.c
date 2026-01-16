#include <stdio.h>

#include "fsm.h"

void init_fsm(fsm_t *fsm, enum state initial_state,
              void (*ev)(fsm_t *, int event),
              void (*st)(fsm_t *, enum state )) {


                fsm->current_state = initial_state;
                fsm->on_event = ev;
                fsm->new_state = st;
            
              }

void fsm_new_state(fsm_t * self, enum state new_state)
{
    printf("FSM: state change from %d to %d\n", self->current_state, new_state);
    self->current_state = new_state;
}