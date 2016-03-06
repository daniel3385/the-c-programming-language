#include <stdio.h>
#include <ctype.h>

#define number_of_characters 26

/* print a histogram of the frequencies of differente characters in its inputs  */

/* IN-> inside a word, OUT-> outside a word */
typedef enum {
    ST_OUT = 0, ST_IN
} STATES;

typedef enum {
        EVT_CHAR = 0, EVT_SPACE
} EVENTS;

char character_letter[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int character[number_of_characters] = {0};

void print(void ) {
	int i,j;
	for(i = 0; i < number_of_characters-1; i++){
		printf("%c=", character_letter[i]);
		for(j = 0; j < character[i]; j++) {
			printf("*");
		}
	printf("\n");
	}
}

int find_index( const char a[], int size, int value )
{
    int index = 0;

    while ( index < size && a[index] != value ) ++index;

    return ( index == size ? -1 : index );
}

STATES analyze_event(int c, EVENTS event, STATES state) {
	c = tolower(c);
	switch(state) {
		case ST_OUT:
		switch(event) {
			case EVT_CHAR:
				state = ST_IN;
				if(c >= character_letter[0] && c <= character_letter[number_of_characters-1]) {
					// FIXME
					++character[find_index(character_letter, number_of_characters, c)];
				}
				break;

			case EVT_SPACE:
			/* do nothing */
			break;
		}
		break; /* end ST_OUT */

		case ST_IN:
		switch(event) {
			case EVT_CHAR:
				if(c >= character_letter[0] && c <= character_letter[number_of_characters-1]) {
					// FIXME
					++character[find_index(character_letter, number_of_characters, c)];
					//++character[character_letter[c]];
				}
				break;

			case EVT_SPACE:
				state = ST_OUT;
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
	print(); /*put the histogram*/
	return 0;
}
