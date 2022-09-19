#if	!defined(_REPEATER_leds_h)
#define	_REPEATER_leds_h

typedef struct LEDConfig ledconfig_t;
struct LEDConfig {
   int		*pin;
   char		*name;		/* name for the pin (11 char) */
   bool		*state;		/* pointer to current state */
};

extern const unsigned long pin_tx_led;
extern const unsigned long pin_rx_led;
extern const unsigned long pin_conflict_led;
extern const unsigned long pin_heartbeat_led;

#endif
