/*
 * Thread for housekeeping (statistics, io, etc)
 *
 * This should be kept fast and lean.
 */
#include "repeater.h"

static THD_WORKING_AREA(twa_maid, 128);
thread_t *thr_maid = NULL;

static THD_FUNCTION(thr_maid_fn, arg) {
   systimestamp_t now = 0;
   chRegSetThreadName("maid");

   // play audio then yield
   while(true) {
      now = chVTGetTimeStamp();

      /* tail timeout expired */ 
      if ((MyState == ST_TAIL) && (now >= tm_tail_expire)) { 
         /* play a courtesy tone */
         play_melody("bumblebee");
         tm_tail_expire = 0;
         PTT(false, false);
         SetState(ST_IDLE);
      }

      /* has TOT expired? */
      if (now >= tm_tot_expire) {
         play_melody("descend");
         PTT(false, false);

         /* add a penalty for exceeding TOT */
         tm_cooldown_expire = now + tm_cooldown;
         SetState(ST_COOLDOWN);
      }

      /* has cooldown expired? */
      if ((MyState == ST_COOLDOWN) && now >= tm_cooldown_expire) {
         PTT(true, true);
         play_melody("ascend");
         PTT(false, false);
         SetState(ST_IDLE);
      }

      chThdYield();
   }
}

void thr_maid_start(void) {
    if (!thr_maid) {
       thr_maid = chThdCreateStatic(twa_maid, sizeof(twa_maid), NORMALPRIO, thr_maid_fn, NULL);
   }
}
