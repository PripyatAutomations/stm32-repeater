/*
 * layout some stuff in EEPROM so settings can be stored
 * 
 * Add new settings at the end.
 */
#if	!defined(_REPEATER_eeprom_h)
#define	_REPEATER_eeprom_h

#define	EE_CHECKSUM	0	/* 16 bit checksum of the EEPROM */
#define	EE_CALLSTART	2	/* string: callsign */
#define	EE_CALLEND	18
#define	EE_GREEDY_TOT	19	/* bool: 'greedy' TOT mode? */
#define	EE_TOT		20	/* int: Talk Timeout */
#define	EE_TOT_COOLDOWN	22	/* int: Cooldown after TOT expired */
#define	EE_PIN_TX_COR	24	/* byte: IO pin for COR on TX radio */
#define	EE_PIN_RX_COR	25	/* byte: IO pin for COR on RX radio */
#define	EE_PIN_PTT	26	/* byte: IO pin for PTT */
#define	EE_PIN_TX_LED	27	/* byte: IO pin for TX activity */
#define	EE_PIN_RX_LED	28	/* byte: IO pin for RX activity */
#define	EE_PIN_CONFLICT_LED 29	/* byte: IO pin for CONFLICTs */
#define	EE_TAIL_TIME	30	/* byte: tail time */
#define	EE_ID_WPM	31	/* byte: words per minute for CW ID */
#define	EE_ID_TONE	32	/* int: frequency of CW tones */
#define	EE_ID_ENABLE	34	/* bool: morse ID? */
#define	EE_ID_QUIET_ENABLE 35	/* bool: ID quiet hours? */
#define	EE_ID_QUIET_START 36	/* int: time to start quiet hours */
#define	EE_ID_QUIET_END	38	/* int: time to stop quiet hours */

/* 'security' */
#define	EE_PASSWORD	40	/* int: admin password (4 digits) */
#define	EE_PASSWORD_SHUTDOWN 42	/* int: shutdown password (4 digits) */
#define	EE_TOTP_SEED	44	/* long: seed for TOTP generator (keep secret) */
#define	EE_TOTP_LIFETIME 48	/* int: lifetime of TOTP tokens (seconds) */

#endif
