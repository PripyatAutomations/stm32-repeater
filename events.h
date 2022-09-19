#if	!defined(_REPEATER_events_h)
#define	_REPEATER_events_h

/* */
typedef struct rpt_event rpt_event_t;
struct rpt_event {
    rpt_event_t		*head, *next;
    char name[13];			/* 12 char name */
    bool (*callback)(void *arg);	/* callback */
};

#endif
