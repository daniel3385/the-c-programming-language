#include <stdio.h>
#include <string.h>

/* Remove all comments from a C program */

typedef enum {
    ST_NORMAL = 0, ST_BAR1, ST_BAR2, ST_STAR1, ST_STAR2
} STATES;

typedef enum {
        EV_CHAR = 0, EV_BAR, EV_STAR
} EVENTS;

STATES analyze_event(int c, EVENTS event, STATES state, FILE *out) {
        switch(state) {
                case ST_NORMAL:
                switch(event) {
                        case EV_CHAR:
                                putc(c, out);
                                break;

                        case EV_BAR:
							state = ST_BAR1;
                        break;
                }
                break; /* end ST_NORMAL */

                case ST_BAR1:
                switch(event) {
                        case EV_CHAR:
                                putc('/', out);
								putc(c, out);
								state = ST_NORMAL;
                                break;

                        case EV_BAR:
                                state = ST_BAR2;
                                break;

                        case EV_STAR:
                                state = ST_STAR1;
                                break;
                }
                break; /* end ST_BAR1 */

                case ST_BAR2:
                switch(event) {
                        case EV_CHAR:
							if(c == '\n') 
								state = ST_NORMAL;
							break;
                }
                break; /* end ST_BAR2 */

                case ST_STAR1:
                switch(event) {
                        case EV_STAR:
							state = ST_STAR2;
							break;
                }
                break; /* end ST_STAR1 */

                case ST_STAR2:
                switch(event) {
                        case EV_BAR:
							state = ST_NORMAL;
							break;

                        case EV_STAR:
							putc('*', out);
							state = ST_STAR1;
							break;
		
						default:
							putc('*', out);
							putc(c, out);
							break;
                }
                break; /* end ST_STAR2 */
        }
        return state;
}

int main(int argc, char *argv[]) {

	FILE *in = fopen(argv[1],"r");
	FILE *out = fopen("output.c","w");

	int c;
	STATES state = ST_NORMAL;
	EVENTS event;

	while((c=getc(in)) != EOF) {
		switch (c) {
			case '/':
				event = EV_BAR;
				break;
			case '*':
				event = EV_STAR;
				break;
			default:
				event = EV_CHAR;
				break;
		}		
		state = analyze_event(c, event, state, out);
	}
	return 0;
}
