#include "repeater.h"

void rx_cor_change(void) {
   int state = palReadLine(pin_rx_cor);

   if (state) {
      /* count it */
      stats.cnt_rx_cor++;

      /* RX light on */
      st_rx_cor = true;
      palSetLine(pin_rx_led);

      /* Turn on transmitter */
      PTT(true, true);
   } else {
      /* RDX light off */
      st_rx_cor = false;
      palClearLine(pin_rx_led);

      /* greedy TOT enforces cooldown */
      if (!greedy_tot) {
         tm_tot_expire = 0;
         SetState(ST_IDLE);
      }
   }
}

/* try to track interference on our output channel */
void tx_cor_change(void) {
  int state = palReadLine(pin_tx_cor);

  if (state) {
     st_tx_cor = true;
     stats.tm_tx_cor_start = now;
     stats.cnt_tx_cor++;

     /* Turn on CONFLICT (yellow) light and disable TX for a bit */
     palSetLine(pin_conflict_led);
     SetState(ST_CONFLICT);
  } else {
     st_tx_cor = false;

     if (stats.tm_tx_cor_start > 0) {
        stats.cnt_tx_cor_time += now - stats.tm_tx_cor_start;
        stats.tm_tx_cor_start = 0;
     }

     /* Turn off CONFLICT (yellow) light */
     palClearLine(pin_conflict_led);
     SetState(old_state);
  }
}
