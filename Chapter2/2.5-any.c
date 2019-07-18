#include <stdio.h>

int any(char s1[], char s2[]);

main()
{
	int pos;
	char s1[] = "hello world";
	char s2[] = "a";

	pos = any(s1, s2);
	printf("%d\n", pos);
}

int any(char s1[], char s2[])
{
	int i, j, k ;

	for (i = 0; s1[i] != '\0'; ++i) {
		if (s1[i] == s2[0]) {
			for (j = 0, k = 0; s2[j] == s1[i + k] && s1[i + k] != '\0' && s2[j] != '\0'; ++j, ++k) {
				;
			}
			if (s2[j] == '\0') {
				return i;
			}
		}
	}
	return -1;
}
