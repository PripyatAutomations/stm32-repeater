/*
 * Thread for audio recording (for DTMF decoding)
 *
 * Here we record samples into a circular buffer to be collected by other threads
 *
 * This is mainly used for DTMF detection
 */
#include "repeater.h"

static THD_WORKING_AREA(twa_record, 128);
thread_t *thr_record = NULL;

static THD_FUNCTION(thr_record_fn, arg) {
   chRegSetThreadName("record");

   while(true) {
      /* do stuff */
      chThdYield();
   }
}

void thr_record_start(void) {
    if (!thr_record) {
       thr_record = chThdCreateStatic(twa_record, sizeof(twa_record), NORMALPRIO, thr_record_fn, NULL);
   }
}
