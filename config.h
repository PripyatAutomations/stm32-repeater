/*
 * config.h: DO NOT EDIT! AUTO-GENERATED!
 *
 * Edit repeater.conf and run ./configure instead!
 */
#if	!defined(_REPEATER_config_h)
#define	_REPEATER_config_h

/* default state of greedy_tot */
#define	DEFAULT_GREEDY_TOT	false

#define	DEFAULT_CALL		"N0CALL"

/**** Inputs ****/
#define	TX_COR_PIN		3		/* confirmed */
#define	RX_COR_PIN		2		/* confirmed */

/**** Outputs *****/
#define	TX_PTT_PIN		11
#define	TX_TONE_PIN		8		/* confirmed */

/**** Status LEDs ****/
#define	TX_LED			PAL_LINE(GPIOB, 9U)	/* when we are keying transmitter */
#define	RX_LED			PAL_LINE(GPIOB, 8U)	/* when we hear on our input freq */
#define	CONFLICT_LED		PAL_LINE(GPIOB, 10U)	/* show when someone TXes on our output */
#define	HEARTBEAT_LED		PAL_LINE(GPIOB, 13U)	/* heartbeart light */

/* ********* */
#define	DEFAULT_TOT		160
#define	DEFAULT_COOLDOWN	30		/* delay after TOT expire */
#define	DEFAULT_TAIL		3		/* hold PTT open for a few second after over */

/* ID / morse encoder */
#define	DEFAULT_ID_WPM		25
#define	DEFAULT_ID_TONE		600		/* freq in hz for CW playback */
#define	DEFAULT_IDLE_ID		false		/* Dont ID when idle */

/* Quiet Times (No ID if idle) */
#define	DEFAULT_ID_QUIET_START	2100		/* disable at 9pm */
#define	DEFAULT_ID_QUIET_END	0600		/* re-enable at 6am */
#define	DEFAULT_ID_QUIET_ENABLE	true		/* enable quiet times? */

/* 'security' */
#define	DEFAULT_PASSWORD	"4321"		/* default admin password */
#define	DEFAULT_PASSWORD_SHUTDOWN "12345678"	/* default shutdown password */
#define	DEFAULT_TOTP_SEED	0xc99a8ffa	/* seed for TOTP system */
#define	DEFAULT_TOTP_LIFETIME	60		/* TOTP lifetime (seconds) */

#endif
