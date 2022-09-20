#if	!defined(_REPEATER_events_h)
#define	_REPEATER_events_h

#define	MAX_EVENTS	256

/* */
typedef struct rpt_event rpt_event_t;
struct rpt_event {
    rpt_event_t		*head, *next;
    char name[13];			/* 12 char name */
    bool (*callback)(void *arg);	/* callback */
};

extern bool event_check_all(void);
extern bool event_register(rpt_event_t *event);
extern bool event_delete(rpt_event_t *event);

#endif
