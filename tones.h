#if	!defined(_REPEATER_tones_h)
#define	_REPEATER_tones_h
#include "notes.h"

typedef enum NoteWavetype NoteWavetype;
enum NoteWavetype {
    WAVE_SINE = 0,
    WAVE_SQUARE,
    WAVE_TRIANGLE
};

/* Allow making an array of notes to play for tunes */
typedef struct Note Note;
/* Use freq: -1 for silence */
/* If delay is 0, play sequentially using len to time it */
struct Note {
    unsigned int delay;		/* offset from beginning of sequence to now */
    unsigned int len;
    int freq;
    int volume;			/* volume */
    NoteWavetype shape;
};

extern void tone_start(Note *np);
extern void tone_stop(void);

/* play various simple tones */
extern void play_melody_real(Note *melody);
extern void play_melody(const char *name);

#endif
