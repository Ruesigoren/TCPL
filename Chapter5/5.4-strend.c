#include <stdio.h>

int strend(char *s1, char * s2);

main()
{
	char s1[] = "orld!";
	char s2[] = "world!";

	printf("%d\n", strend(s1, s2));
}

int strend(char *s1, char * s2)
{
	char *t1, *t2;

	t1 = s1;
	t2 = s2;
	while (*s1) {
		s1++;
	}
	while (*s2) {
		s2++;
	}
	while (*s1-- == *s2--) {
		if(s1 == t1 || s2 == t2)
			break;
	}
	if (s2 == t2 && s1 - t1 >= 0) {
		return 1;
	}
	return 0;
}
