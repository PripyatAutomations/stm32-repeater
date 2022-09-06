/*
 * Thread for audio playback
 *
 * Here we deal with a few kinds of audio:
 *	wav clips from sd card (not yet)
 *	single tone melodies
 */
#include "repeater.h"

static THD_WORKING_AREA(twa_playback, 128);
thread_t *thr_playback = NULL;

static THD_FUNCTION(thr_playback_fn, arg) {
   chRegSetThreadName("playback");

   while(true) {
      // Give up rest of our timeslot...
      chThdYield();
   }
}

void thr_playback_start(void) {
    if (!thr_playback) {
       thr_playback = chThdCreateStatic(twa_playback, sizeof(twa_playback), NORMALPRIO, thr_playback_fn, NULL);
   }
}
