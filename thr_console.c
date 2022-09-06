/*
 * Thread for serial consoles
 *
 * Here we read all the serial ports and do the needful
 */
#include "repeater.h"

static THD_WORKING_AREA(twa_console, 128);
thread_t *thr_console = NULL;

static THD_FUNCTION(thr_console_fn, arg) {
   chRegSetThreadName("console");

   while(true) {
      /* XXX: Poll the esp8266 serial bridge */
      chThdYield();
   }
}

void thr_console_start(void) {
    if (!thr_console) {
       thr_console = chThdCreateStatic(twa_console, sizeof(twa_console), NORMALPRIO, thr_console_fn, NULL);
   }
}

/**********
 * Parser *
 **********/
