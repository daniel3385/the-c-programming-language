#include <stdio.h>

/* reverse character string s  */

void reverse(char s[], int end) {
	char tmp;
	int i = 0;
	end--; /* keep '\n' at the end*/

	while (i < (end-1)/2) {
		tmp = s[i];
		s[i++] = s[end-1];
		s[(end--)-1] = tmp;
	}
}

int main () {

	char teste[] = "daniel";

	printf("%s\n", teste);
	reverse(teste, sizeof(teste));
	printf("%s\n", teste);

	return 0;
}
