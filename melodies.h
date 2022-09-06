#if	!defined(_MELODIES_H)
#define	_MELODIES_H
/*
 * Notes are played one after another.
 * freq sets the tone and len is how long in ms to play
 *
 * Use freq = -1, len = time to play silence
 * Use freq =  0, len = 0 for end of melody marker
 *
 * Be sure to add it to the table at the end so it's playable by name!
 */
Note melody_3up[] = {
   { .len = 100, .freq = 400 },
   { .len = 100, .freq = 600 },
   { .len = 100, .freq = 800 },
   { .len = 0, .freq = 0 }
};

Note melody_3down[] = {
   { .len = 100, .freq = 800 },
   { .len = 100, .freq = 600 },
   { .len = 100, .freq = 400 },
   { .len = 0, .freq = 0 }
};

Note melody_ascend[] = {
   { .len = 50, .freq = 500 },
   { .len = 50, .freq = 750 },
   { .len = 50, .freq = 1000 },
   { .len = 0, .freq = 0 }
};

Note melody_apollo[] = {
   { .len = 200, .freq = 2475 },
   { .len = 0, .freq = 0 }
};

Note melody_beep[] = {
   { .len = 100, .freq = 880 },
   { .len = 0, .freq = 0 }
};

Note melody_boop[] = {
   { .len = 100, .freq = 440 },
   { .len = 0, .freq = 0 }
};

Note melody_beeboo[] = {
   { .len = 200, .freq = 800 },
   { .len = 200, .freq = 400 },
   { .len = 0, .freq = 0 }
};

Note melody_blastoff[] = {
   { .len = 50, .freq = 500 },
   { .len = 50, .freq = 1500 },
   { .len = 50, .freq = 2500 },
   { .len = 50, .freq = 500 },
   { .len = 0, .freq = 0 }
};

Note melody_bumblebee[] = {
   { .len = 100, .freq = 300 },
   { .len = 100, .freq = 500 },
   { .len = 100, .freq = 660 },
   { .len = 0, .freq = 0 }
};

Note melody_comet[] = {
   { .len = 200, .freq = 500 },
   { .len = 100, .freq = 540 },
   { .len = 0, .freq = 0 }
};

Note melody_descend[] = {
   { .len = 50, .freq = 1000 },
   { .len = 50, .freq = 750 },
   { .len = 50, .freq = 500 },
   { .len = 0, .freq = 0 }
};

Note melody_nextel[] = {
   { .len = 30, .freq = 1760 },
   { .len = 20, .freq = -1 },
   { .len = 30, .freq = 1760 },
   { .len = 20, .freq = -1 },
   { .len = 30, .freq = 176 },
   { .len = 0, .freq = 0 }
};

Note melody_overhere[] = {
   { .len = 40, .freq = 800 },
   { .len = 60, .freq = -1 },
   { .len = 40, .freq = 1200 },
   { .len = 60, .freq = -1 },
   { .len = 40, .freq = 1400 },
   { .len = 0, .freq = 0 }
};

Note melody_satpass[] = {
   { .len = 40, .freq = 1200 },
   { .len = 20, .freq = -1 },
   { .len = 40, .freq = 1000 },
   { .len = 10, .freq = -1 },
   { .len = 40, .freq = 800 },
   { .len = 0, .freq = 0 }
};

Note melody_shootingstar[] = {
   { .len = 200, .freq = 800 },
   { .len = 100, .freq = 540 },
   { .len = 0, .freq = 0 }
};

Note melody_tumbleweed[] = {
   { .len = 50, .freq = 1000 },
   { .len = 50, .freq = 800 },
   { .len = 50, .freq = 600 },
   { .len = 0, .freq = 0 }
};

Note melody_waterdrop[] = {
   { .len = 40, .freq = 500 },
   { .len = 20, .freq = 600 },
   { .len = 20, .freq = 700 },
   { .len = 40, .freq = 800 },
   { .len = 40, .freq = 400 },
   { .len = 0, .freq = 0 }
};

Note melody_whippoorwill[] = {
   { .len = 40, .freq = 1330 },
   { .len = 20, .freq = -1 },
   { .len = 40, .freq = 990 },
   { .len = 10, .freq = -1 },
   { .len = 40, .freq = 800 },
   { .len = 0, .freq = 0 }
};

Note melody_yellowjacket[] = {
   { .len = 50, .freq = 330 },
   { .len = 50, .freq = 500 },
   { .len = 50, .freq = 660 },
   { .len = 0, .freq = 0 }
};

typedef struct Melody Melody;
struct Melody {
   const char *name;
   Note *notes;
};

/* Table mapping names to tunes */
struct Melody MyMelodies[] = {
   { "3up",		melody_3up },
   { "3down",		melody_3down },
   { "ascend",		melody_ascend },
   { "apollo",		melody_apollo },
   { "beep",		melody_beep },
   { "boop",		melody_boop },
   { "beeboo",		melody_beeboo },
   { "blastoff",	melody_blastoff },
   { "bumblebee",	melody_bumblebee },
   { "comet",		melody_comet },
   { "descend",		melody_descend },
   { "nextel",		melody_nextel },
   { "overhere",	melody_overhere },
   { "satpass",		melody_satpass },
   { "shootingstar",	melody_shootingstar },
   { "tumbleweed",	melody_tumbleweed },
   { "waterdrop",	melody_waterdrop },
   { "whippoorwill",	melody_whippoorwill },
   { "yellowjacket",	melody_yellowjacket }
};

#endif
