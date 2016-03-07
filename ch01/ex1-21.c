#include <stdio.h>

#define TRUE 1
#define FALSE 0

/* entab  */

int main () {

	int c; /* integer to support EOF */
	int has_blank = FALSE;

	while((c=getchar()) != EOF) {
		if(c == '\t' || c == ' '){
			if(has_blank == FALSE) {
				has_blank = TRUE;
				putchar('\t');
			}
		} else {
			has_blank = FALSE;
			putchar(c);
		}
	}
	return 0;
}
