/*
 * simple repeater controller for arduino.
 *
 * Configuration: Edit repeater.conf then run ./configure then build..
 * Building: make clean world
 * Installing: make install
 *
 * Released under MIT license. No warranty of any kind.
 *
 * If it breaks your radio, you get to keep the pieces!
 */
#include "repeater.h"

/* Setup our pin references */

systimestamp_t now = 0;
systimestamp_t tm_start,
       tm_next_id,		/* when should we ID next? */
       tm_cooldown = DEFAULT_COOLDOWN, /* TOT cooldown */
       tm_tail = DEFAULT_TAIL,  /* hold PTT a bit */
       tm_tot_expire,		/* when does TOT expire? */
       tm_tail_expire,
       tm_tot = DEFAULT_TOT,
       tm_cooldown_expire;

const char *callsign = DEFAULT_CALL;

/* Our state machine */
MachineState MyState = ST_OFFLINE, old_state = ST_OFFLINE;

/* pin statuses */
volatile bool st_int = false;	/* interrupt */

/* TX killswitch */
bool Killswitch = false;
bool greedy_tot = DEFAULT_GREEDY_TOT;
bool idle_id = DEFAULT_IDLE_ID;

/*********************
 * End Configuration *
 *********************/
void SetState(enum MachineState state) {
   /* already there, don't clobber old_state */
   if (MyState == state)
      return;

   /* update old_state, if changed then store new state */
   if (old_state != state) { 
      old_state = MyState;
      MyState = state;
   }
}

int main(void) {
   /* chibios init */
   halInit();
   chSysInit();

   /* local setup */
   statistics_init();

   if (pin_tx_cor)
      palSetLineMode(pin_tx_cor, PAL_MODE_INPUT_PULLUP);

   if (pin_rx_cor)
      palSetLineMode(pin_rx_cor, PAL_MODE_INPUT_PULLUP);

   // or PAL_MODE_OUTPUT_OPENDRAIN
   if (pin_tx_ptt)
      palSetLineMode(pin_tx_ptt, PAL_MODE_OUTPUT_PUSHPULL);

   if (pin_tx_led)
      palSetLineMode(pin_tx_led, PAL_MODE_OUTPUT_PUSHPULL);

   if (pin_rx_led)
      palSetLineMode(pin_rx_led, PAL_MODE_OUTPUT_PUSHPULL);

   if (pin_conflict_led)
      palSetLineMode(pin_conflict_led, PAL_MODE_OUTPUT_PUSHPULL);

   /* Start threads */
   thr_console_start();
   thr_dtmf_start();
   thr_maid_start();
   thr_playback_start();
   thr_record_start();

   /* Set state machine to IDLE status */
   MyState = ST_IDLE;

   while (true) {
      update_leds();
      palSetPad(GPIOC, 13U);
      chThdSleepMilliseconds(500);
      palClearPad(GPIOC, 13U);
      chThdSleepMilliseconds(500);
      chThdSleepMilliseconds(500);
   }
}
