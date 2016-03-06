#include <stdio.h>

#define TRUE  1
#define FALSE 0

/* remove trailing blanks, tabs and entirely blank lines  */


int main () {

 	int c;
	int has_blank = FALSE;

    while ((c = getchar()) != EOF) {
		if(c == ' ' || c== '\t' ){
			if (has_blank) {
				/*do nothing, skip other blanks*/
			} else {
				has_blank = TRUE;
				putchar(' ');
			}
		} else {
			putchar(c);
			has_blank = FALSE;
		}
    }
	return 0;
}
