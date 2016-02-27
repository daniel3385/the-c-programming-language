#include <stdio.h>

/* 	
	Verify the expression getchar()  
	Type a string then EOF to finish
*/

int main () {

	int c;

	while((c=getchar()) != EOF) {}

	printf("getchar() != EOF :%d\n");

	return 0;
}
