/* primitives for synchronizing clock and using RTC */
#include "repeater.h"

/* convert a timestamp from the ntp process to a system timestamp */
systimestamp_t clocksync_parse_ts(const char *timestr) {
   systimestamp_t new_time = 0;

   if (timestr == NULL)
      return 0;

   sscanf(timestr, "%llu", &new_time);

   return new_time;
}

/* set the rtc hardware (if present) */
bool clocksync_set_rtc(systimestamp_t ts) {
   systimestamp_t sysclock_ts = chVTGetTimeStamp();

   if (ts == 0 || ts < sysclock_ts) {
      // We are not a time traveller...
      return false;
   }

   /* Set the global now time */
   now = ts;

   /* XXX: push it up to the RTC */

   /* If we made it this far, return success */
   return true;
}

bool clocksync_set_rtc_s(const char *timestr) {
   systimestamp_t new_ts = clocksync_parse_ts(timestr);
   return clocksync_set_rtc(new_ts);
}

/* for now we do not support reading the RTC back */
bool clocksync_rtc_to_sysclock(void) {
    systimestamp_t old_ts = now;
    /* do the thing */
    return false;
}

