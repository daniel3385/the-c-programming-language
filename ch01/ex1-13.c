#include <stdio.h>

/* print a histogram of the lenghts of words in its inputs  */

/* IN-> inside a word, OUT-> outside a word */
typedef enum {
    ST_OUT = 0, ST_IN
} STATES;

typedef enum {
        EVT_CHAR = 0, EVT_SPACE
} EVENTS;

STATES analyze_event(int c, EVENTS event, STATES state)
{
	switch(state) {
		case ST_OUT:
		switch(event) {
			case EVT_CHAR:
				state = ST_IN;
				printf("*");
				break;

			case EVT_SPACE:
			/* do nothing */
			break;
		}
		break; /* end ST_OUT */

		case ST_IN:
		switch(event) {
			case EVT_CHAR:
				printf("*");
				break;

			case EVT_SPACE:
				state = ST_OUT;
				printf("\n");
				break;
		}
		break; /* end ST_IN */
	}
	return state;
}

int main () {

 	int c;
	STATES state = ST_OUT;
	EVENTS event;

    while ((c = getchar()) != EOF) {
		if(c == ' ' || c== '\t' || c == '\n'){
			event = EVT_SPACE;
		} else {
			event = EVT_CHAR;
		}
	state = analyze_event(c, event, state);
	
    }
	return 0;
}
