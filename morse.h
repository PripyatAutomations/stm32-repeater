extern const char morse_index[];
extern const char *morse_encodings[];
extern const int morse_encoding_count;
extern unsigned int morse_wpm;
extern unsigned int morse_tone;
extern unsigned int morse_dit_time, morse_dah_time;
extern void morse_set_wpm(unsigned int wpm);
extern void morse_play(const char *data);
extern const char *morse_find_char(const char c);
