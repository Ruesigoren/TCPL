#include <stdio.h>

void strcat(char *s, char *t);

main()
{
	char s1[20] = "hello";
	char s2[] = " world!";

	strcat(s1, s2);

	printf("%s\n", s1);
}

void strcat(char *s, char *t)
{
	while (*s) {
		s++;
	}
	while (*s++ = *t++) {
		;
	}
}