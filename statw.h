#define STATW_Y = 3;
#define STATW_X = 13;

WINDOW	       *statw_create();
void		statw_delete(WINDOW *);
void		show_status(char *);
