#include <stdio.h>

int strend(char *s, char *t);

int main()
{
	char s1[] = "orld!";
	char s2[] = "world!";

	printf("%d\n", strend(s2, s1));
	getchar();
}

int strend(char *s, char *t)
{
	char *ps, *pt;
	
	ps = s;
	pt = t;
	for (; *s; s++) {
		;
	}
	for (; *t; t++) {
		;
	}
	for (; *s == *t; s--, t--) {
		if (s == ps || t == pt) {
			break;
		}
	}
	if (*s == *t && t == pt && *s != '\0') {
		return 1;
	}
	else {
		return 0;
	}
}