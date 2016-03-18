#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* returns first location s wheres any character of t occurs  */

int any(char *s, char *t) {
	int i, j;
	for(i = 0; s[i] != '\0'; i++){
		for(j = 0; t[j] != '\0'; j++){
			if(s[i] == t[j++]) {
				return i;
			}
		}
	}
	return -1;
}

void main() {
	int match;
	char *s = malloc(strlen("daniel")+1);
	char *t = malloc(strlen("lgdhtposxl")+1);
	strcpy(s, "daniel");
	strcpy(t, "lgdhtposxl");
	
	match = any(s, t);

	printf("s=%s \tt=%s\n", s, t);
	printf("match=%d \n", match);

	free(s);
	free(t);
}
