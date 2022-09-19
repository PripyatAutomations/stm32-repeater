#if	!defined(_REPEATER_led_cfg_h)
#define	_REPEATER_led_cfg_h

ledconfig_t LEDs[] = {
  { &pin_tx_led, 	"TX", 		&st_tx_ptt },
  { &pin_rx_led, 	"RX", 		&st_rx_cor },
  { &pin_conflict_led,	"CONFLICT",	&st_tx_cor },
  { &pin_heartbeat_led,	"HB",		NULL },
  { 0, 			NULL,		false }
};

#endif
