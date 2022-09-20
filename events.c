/*
 * Event handler system
 */
#include "repeater.h"

/* our event-queue */
rpt_event_t events[MAX_EVENTS];

bool event_check_all(void) {
   return false;
}

bool event_register(rpt_event_t *event) {
   return false;
}

bool event_delete(rpt_event_t *event) {
   return false;
}
