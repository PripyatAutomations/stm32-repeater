#if	!defined(_REPEATER_leds_h)
#define	_REPEATER_leds_h

typedef struct LEDConfig ledconfig_t;
struct LEDConfig {
   unsigned long *pin;
   char		*name;		/* name for the pin (11 char) */
   bool		*state;		/* pointer to current state */
};

extern unsigned long pin_tx_led;
extern unsigned long pin_rx_led;
extern unsigned long pin_conflict_led;
extern unsigned long pin_heartbeat_led;

#endif
