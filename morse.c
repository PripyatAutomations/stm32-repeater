/*
 * A primitive morse encoder + sounder for 'duino
 */

/*
 * Only characters contained here are valid for morse_play().
 *
 * All other characters will be ignored.
 */ 
#include "repeater.h"
const char morse_index[] = 
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-/.$:;&!?,'()=+_\"";

/* Mapping of symbols into Morse Code */ 
const char *morse_encodings[] = {
    /* A */ ".-",      /* B */ "-...",    /* C */ "-.-.",
    /* D */ "-..",     /* E */ ".",       /* F */ "..-.",
    /* G */ "--.",     /* H */ "....",    /* I */ "..",
    /* J */ ".---",    /* K */ "-.-",     /* L */ ".-..",
    /* M */ "--",      /* N */ "-.",      /* O */ "---",
    /* P */ ".-.",     /* Q */ "--.-",    /* R */ ".-.",
    /* S */ "...",     /* T */ "-",       /* U */ "..-",
    /* V */ "...-",    /* W */ ".--",     /* X */ "-..-",
    /* Y */ "-.--",    /* Z */ "--..",    /* 0 */ "-----",
    /* 1 */ ".----",   /* 2 */ "..---",   /* 3 */ "...--",
    /* 4 */ "....-",   /* 5 */ ".....",   /* 6 */ "-....",
    /* 7 */ "--...",   /* 8 */ "---..",   /* 9 */ "----.",
    /* - */ "-....-",  /* / */ "-..-.",   /* . */ ".-.-.-",
    /* $ */ "...-..-", /* : */ "---...",  /* ; */ "-.-.-.",
    /* & */ ".-...",   /* ! */ "-.-.--",  /* ? */ "..--..",
    /* , */ "--..--",  /* ' */ ".----.",  /* ( */ "-.--.",
    /* ) */ "-.--.-",  /* = */ "-...-",   /* + */ ".-.-.",
    /* _ */ "..--.-",  /* " */ ".-..-.",  /* @ */ ".--.-.",
    /*' '*/ "       ",
};

const int morse_encoding_count = (sizeof(morse_encodings) / sizeof(morse_encodings[0]));

/* Set via morse_set_wpm to recalculate value below automatically */
unsigned int morse_wpm = DEFAULT_ID_WPM;
unsigned int morse_tone = DEFAULT_ID_TONE;

/* These must be recalculated if morse_wpm is changed, use morse_set_wpm to change */
unsigned int morse_dit_time = 0,
             morse_dah_time = 0;

void morse_set_wpm(unsigned int wpm) {
     morse_wpm = wpm;

     if (morse_wpm > 0) {
        /* calculate elememnt time in milliseconds */
        morse_dit_time = (morse_wpm * 50) / 60;
        morse_dah_time = morse_dit_time * 3;
     }
}


/*
 * Look up the encoding for a character using
 * the index and encodings array
 */
const char *morse_find_char(const char c) {
   int i = 0, end = strlen(morse_index);

   for (i = 0; i < end; i++) {
      /* have we found our encoding? */
      if (morse_index[i] == c)
         /* Return it! */
         return morse_encodings[i];
   }

   /* nope, invalid character */
   return NULL;
}

void morse_play_char(const char data) {
    const char *ep = NULL;
    Note mynote;
    
    if ((ep = morse_find_char(data)) != NULL) {
       for (size_t c = 0; c < strlen(ep); c++) {
           /* default to inter-character delay */
           int cw_pause = 3;

           /* play the sound */
           if (ep[c] == ' ') {
              tone_stop();
              /* pause between words */
              cw_pause = 7;
           } else if (ep[c] == '.') {
              mynote.len = morse_dit_time;
              mynote.freq = morse_tone;
              tone_start(&mynote);
           } else if (ep[c] == '-') {
              mynote.len = morse_dah_time;
              mynote.freq = morse_tone;
              tone_start(&mynote);
          }

          /* inter-symbol/word pauses */
          if (cw_pause > 0)
             chThdSleepMilliseconds(morse_dit_time * cw_pause);
       }
    }

    /* stop any tone that might be playing */
    tone_stop();
}

/* Play a string (ID?) */
void morse_play(const char *data) {
    size_t dlen = strlen(data);

    if (!dlen)
       return;

    /* step through the string */
    for (size_t i = 0; i < strlen(data); i++) {
        /************
         * Prosigns *
         ************/
        /* New paragraph (\n\n)? */
        if (i < (dlen - 1) && data[i] == '\n' && data[i+1] == '\n') {
           morse_play_char('B');
           morse_play_char('T');
           i++; /* skip an extra character in input */
        } else if (data[i] == '\n') { /* New line? */
           morse_play_char('A');
           morse_play_char('A');
        } else {
           /* play just this character */
           morse_play_char(data[i]);
        }
    }
}
