#include <stdio.h>

/* "fold" long input lines into two */

/*number of characters per line*/
#define LIMIT 10 

int main() {

	int c; /* to support EOF  */
	int number = 0;

	while((c=getchar()) != EOF) {
		if(number == LIMIT) {
			printf("\n");
			number = 0;
		} else {
			putchar(c);
			++number;
		}
	}
	return 0;
}
