#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size*/
#define MINLINE 3 /* minimum input line size*/

/* Print lines that are longer than MINLINE */

/* getline: read a line into s, return length  */
int getline(char s[], int lim) {
	int c, i;

	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

/* print longest input line */
int main() {
	int len; /* current line length */
	char line[MAXLINE]; /* current input line  */

	while ((len = getline(line, MAXLINE)) > 0)
		if (len > MINLINE) {	
			printf("%s", line);
		}
	return 0;
}
