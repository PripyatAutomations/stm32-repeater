#include "repeater.h"
#include "led_cfg.h"

unsigned long pin_tx_led = TX_LED;
unsigned long pin_rx_led = RX_LED;
unsigned long pin_conflict_led = CONFLICT_LED;
unsigned long pin_heartbeat_led = HEARTBEAT_LED;

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
