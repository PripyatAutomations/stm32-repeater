#include "tones.h"
#include "repeater.h"
#include "melodies.h"

#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)

void tone_start(Note *np) {
}

void tone_stop(void) {
}

void play_melody_real(Note *melody) {
   int i = 0;
   do {
     /* is this a stop note? */
     if (melody[i].freq == 0 && melody[i].len == 0) {
        tone_stop();
        return;
     }

     /* it must be a valid note, play it */
     tone_start(&melody[i]);
     i++;	/* carry on! */
   } while (i < 128);

   /* make sure we leave with tone output OFF */
   tone_stop();
}

void play_melody(const char *name) {
   Melody *mp;

   for (unsigned int i = 0; i < (sizeof(MyMelodies)/sizeof(MyMelodies[0])); i++) {
       if (name == NULL)
          break;

       if (MyMelodies[i].name == NULL)
          continue;

       if (strcasecmp(MyMelodies[i].name, name) == 0) {
          mp = &MyMelodies[i];
          /* Log("Playing melody %s", name); */
          break;
       }
   }

   if (mp != NULL)
      play_melody_real(mp->notes);
}
