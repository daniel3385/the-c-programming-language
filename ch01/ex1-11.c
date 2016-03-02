#include <stdio.h>

/* count the number of words and new lines */

#define	IN 		1
#define	OUT 	0

int main () {

	int c, nw, nl, nc, state; 
	nw = nl = nc = 0;
	state = OUT;

	while((c=getchar()) != EOF) { 
 		++nc;	
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c== '\t') {
			state = OUT;
		} else if (state == OUT) {
				state == IN;
				++nw;
		}
	}
	printf("lines=%d words=%d caracters=%d", nl, nw, nc);
	return 0;
}
