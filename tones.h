#if	!defined(_REPEATER_tones_h)
#define	_REPEATER_tones_h
#include "notes.h"

/* Allow making an array of notes to play for tunes */
typedef struct Note Note;
/* Use freq: -1 for silence */
struct Note {
    unsigned int len;
    int freq;
};

extern void tone_start(Note *np);
extern void tone_stop(void);

/* play various simple tones */
extern void play_melody_real(Note *melody);
extern void play_melody(const char *name);

#endif
