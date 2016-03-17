#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* deletes each character in s that matcher any character in t  */

void squeeze(char *s, char *t) {
	int i,j,k;	
	for(i = j = 0; s[i] != '\0'; i++) {
		for(k = 0; t[k] != '\0'; k++)
			if(s[i] == t[k])
				break; /* exit for k */
			if(t[k] == '\0')
				s[j++] = s[i];
	}
	s[j] = '\0';
}

void main() {
	char *s = (char *)malloc(strlen("daniel")+1); 
	char *t = (char *)malloc(strlen("ni")+1);
	strcpy(s, "daniel");
	strcpy(t, "ni");

	squeeze(s, t);

	printf("s=%s \tt=%s\n", s, t);

	free(s);
	free(t);
}
