#include <stdio.h>

/* copy its input to its output replacing each tab by \t backspace by \b and backslash by \\  */

int main () {

	int c; /* must be integer to assign EOF */
	
	while((c=getchar()) != EOF) {
		switch (c) {

		case '\t':
		putchar('\\');
		putchar('t');
		break;

		case '\b':
		putchar('\\');
		putchar('b');
		break;

		case '\\':
		putchar('\\');
		break;

		default:
		putchar(c);
		break;

		}
	}
	
	return 0;
}
