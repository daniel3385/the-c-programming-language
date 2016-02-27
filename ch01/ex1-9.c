#include <stdio.h>

/* copy its input to its output replacing each string of one or more blanks by a single blank  */

int main () {

	int c; /* must be integer to assign EOF */
	
	while((c=getchar()) != EOF) {
		if(c == ' ') {
			putchar(c);
			while((c=getchar()) == ' ') { } /* jump the other blanks*/
				if (c == EOF) /* end of file, finish */
					return 0;
				putchar(c); /* put first non-blank character after blanks*/
		} else {
			putchar(c);
		}
	}
	
	return 0;
}
