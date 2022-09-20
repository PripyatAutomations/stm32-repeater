#if	!defined(_REPEATER_repeater_h)
#define	_REPEATER_repeater_h

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <stdarg.h>
#include "ch.h"
#include "hal.h"
#include "config.h"
#include <chibios/os/hal/lib/streams/chprintf.h>
#include "clocksync.h"
#include "console.h"
#include "events.h"
#include "eeprom.h"
#include "leds.h"
#include "morse.h"
#include "pcm5102.h"
#include "statistics.h"
#include "tones.h"
#include "totp.h"

#define IS_INDEXABLE(arg) (sizeof(arg[0]))
#define IS_ARRAY(arg) (IS_INDEXABLE(arg) && (((void *) &arg) == ((void *) arg)))
#define ARRAYSIZE(arr) (IS_ARRAY(arr) ? (sizeof(arr) / sizeof(arr[0])) : 0)

typedef unsigned short byte;

typedef enum MachineState {
   ST_OFFLINE = 0,		/* Not running yet */
   ST_KILLSWITCH,		/* TX disabled */
   ST_IDLE,			/* IDLE */
   ST_RX,			/* Receiving (but not repeating) */
   ST_CONFLICT,			/* Receiving on output freq */
   ST_TX,			/* Transmitting repeated audio */
   ST_TAIL,			/* PTT tail timer active */
   ST_COOLDOWN			/* TOT has been exceeded (cooldown) */
} MachineState;

extern systimestamp_t tm_start,
       tm_next_id,		/* when should we ID next? */
       tm_cooldown, 		/* TOT cooldown */
       tm_tail,		        /* hold PTT a bit */
       tm_tot_expire,		/* when does TOT expire? */
       tm_tail_expire,
       tm_tot,
       tm_cooldown_expire,
       now;

/* ptt.c */
extern const unsigned long pin_tx_tone,
                  pin_tx_ptt,
                  pin_tx_cor,
                  pin_rx_cor;

/* pin statuses */
extern bool st_int,	/* interrupt */
            st_hang ,	/* hang timer (squelch tail) */
            st_tx_ptt,	/* PTT */
            st_tx_cor,	/* COR state of TX radio */
            st_rx_cor;	/* COR state of RX radio */


extern MachineState MyState;

/******/
extern bool Killswitch;
extern bool greedy_tot;
extern const char *callsign;

/////////////
// Threads //
/////////////
extern void thr_console_start(void);
extern void thr_dtmf_start(void);
extern void thr_maid_start(void);
extern void thr_playback_start(void);
extern void thr_record_start(void);

///////////
extern void PTT(bool state, bool tail);
extern void SetState(enum MachineState state);
extern void update_leds(void);

extern void rx_cor_change(void);
extern void tx_cor_change(void);

#endif
