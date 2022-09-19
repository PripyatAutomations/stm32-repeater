#include "repeater.h"

const unsigned long pin_tx_ptt = TX_PTT_PIN;
const unsigned long pin_tx_cor = TX_COR_PIN;
const unsigned long pin_rx_cor = RX_COR_PIN;

volatile bool st_tx_ptt = false, /* PTT */
              st_tx_cor = false, /* COR state of TX radio */
              st_rx_cor = false; /* COR state of RX radio */

/* Enable PTT; tail == false stops PTT immediately */
void PTT(bool state, bool tail) {
   if (state) {		/* PTT ON */
     /* dont allow TX if killswitch on */
     if (Killswitch || MyState == ST_KILLSWITCH)
        return;

     /* Set TOT expiry, if not already active */
     if (tm_tot_expire == 0) {
        tm_tot_expire = now + tm_tot;
     }

     /* enforce cooldown timer */
     if (tm_cooldown_expire > now) {
        return;
     }

     /* Dont TX if someone is talking on channel */
     if (MyState == ST_CONFLICT) {
        return;
     }

     /* clear squelch tail expiry if set */
     if (MyState == ST_TAIL)
        tm_tail_expire = 0;

     /* DO IT! */
     palSetLine(pin_tx_led);
     palSetLine(pin_tx_ptt);
     st_tx_ptt = true;			/* set PTT status flag */
     SetState(ST_TX);
   } else {	/* PTT OFF */
     if (MyState == ST_TX || MyState == ST_IDLE) {
        st_tx_ptt = false;			/* clear PTT status flag */

        if (!tail) {
           tm_tail_expire = 0;
           palClearLine(pin_tx_led);
           palClearLine(pin_tx_ptt);
           SetState(ST_IDLE);
        } else if (tm_tot_expire == 0) { /* only if TOT didnt expire */
           /* Start tail timeout */
           tm_tail_expire = now + tm_tail;
           SetState(ST_TAIL);
        }
     } else { /* dunno, turn it off... */
        tm_tail_expire = 0;
        palClearLine(pin_tx_ptt);
        palClearLine(pin_tx_led);
        SetState(ST_IDLE);
     }     
   }
}
