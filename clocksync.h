#if	!defined(_REPEATER_clocksync_h)
#define	_REPEATER_clocksync_h

extern systimestamp_t clocksync_parse_ts(const char *timestr);
extern bool clocksync_set_rtc(systimestamp_t ts);
extern bool clocksync_set_rtc_s(const char *timestr);
extern bool clocksync_rtc_to_sysclock(void);
extern bool clocksync_print_now(void);

#endif
