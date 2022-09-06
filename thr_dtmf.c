/*
 * Thread for DTMF decoding
 *
 * This thread will listen for audio frames from thr_playback
 * and try to detect DTMF in them
 */
#include "repeater.h"

static THD_WORKING_AREA(twa_dtmf, 128);
thread_t *thr_dtmf = NULL;

static THD_FUNCTION(thr_dtmf_fn, arg) {
   chRegSetThreadName("dtmf");
   // play audio then yield
   while(true) {
      // Sleep awhile so we don't thrash, until we have work to do...
//      chThdSleepMilliseconds(500);

      // Give up rest of our timeslot...
      chThdYield();
   }
}

void thr_dtmf_start(void) {
    if (!thr_dtmf) {
       thr_dtmf = chThdCreateStatic(twa_dtmf, sizeof(twa_dtmf), NORMALPRIO, thr_dtmf_fn, NULL);
    }
}
