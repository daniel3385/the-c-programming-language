#include <stdio.h>

/* count blanks, tabs and newlines */

int main () {

	int c; /* must be integer to assign EOF */
	int blanks=0, tabs=0, newlines=0;

	while((c = getchar()) != EOF) {

		switch(c) {

		case ' ':
		blanks++;
		break;

		case '\t':
		tabs++;
		break;

		case '\n':
		newlines++;
		break;

		}
	}

	printf("blanks=%d, tabs=%d, newlines=%d\n",blanks,tabs,newlines);

	return 0;

}

