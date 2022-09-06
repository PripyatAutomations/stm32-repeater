#include "repeater.h"

void update_leds(void) {
// PAL_MODE_OUTPUT_OPENDRAIN
   if (pin_tx_led != 0) {
      if (st_tx_ptt) {
         palSetLine(pin_tx_led);
      } else {
         palClearLine(pin_tx_led);
      }
   }
   if (pin_rx_led != 0) {
      if (st_rx_cor) {
         palSetLine(pin_rx_led);
      } else {
         palClearLine(pin_rx_led);
      }
   }

   if (pin_conflict_led != 0) {
      if (st_tx_cor) {
         palSetLine(pin_conflict_led);
      } else {
         palClearLine(pin_conflict_led);
      }
   }
}
