#include "repeater.h"
Statistics stats;

void statistics_init(void) {
   // Zero out the statistics structure
   memset(&stats, 0, sizeof(stats));
}
