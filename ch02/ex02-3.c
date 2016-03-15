#include <stdio.h>

/* convert hexadecimal to integer  */

int htoi(char *s) {
	int num;
	sscanf(s, "%x", &num);
	return num;
}

void main (){
	char *hexadecimal = "0x820";
	int result;
	result = htoi(hexadecimal);

	printf("hexadecimal=%s \tdecimal=%d\n",hexadecimal, result);

}
		
