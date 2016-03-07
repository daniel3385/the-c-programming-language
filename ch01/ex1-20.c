#include <stdio.h>

#define TRUE 1
#define FALSE 0

/* detab  */

int main () {

	int c; /* integer to support EOF */
	int has_blank = FALSE;

	while((c=getchar()) != EOF) {
		if(c == '\t' || c == ' '){
			if(has_blank == FALSE) {
				has_blank = TRUE;
				putchar(' ');
			}
		} else {
			has_blank = FALSE;
			putchar(c);
		}
	}
	return 0;
}
