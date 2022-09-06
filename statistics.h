#if	!defined(_REPEATER_statistics_h)
#define	_REPEATER_statistics_h
typedef struct Statistics Statistics;

struct Statistics {
       systimestamp_t tm_curr_rx,
              tm_curr_tx,
              tm_tx_cor_start,
              tm_rx_cor_start;

       systimestamp_t cnt_rx_talk,		/* total time RXing */
              cnt_tx_talk;		/* time with PTT keyed */

       systimestamp_t cnt_tx_cor_time,
              cnt_rx_cor_time;

       unsigned long cnt_tx_cor,	/* incoming COR on TX chan */
              cnt_rx_cor;		/* incoming COR on RX chan */
};
extern Statistics stats;
extern void statistics_init(void);

// !define(_REPEATER_statistics_h)
#endif
