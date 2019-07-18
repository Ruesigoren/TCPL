#include <stdio.h>

void expand(char s1[], char s2[]);

main()
{
	char t1[] = "1-3-7aa";
	char t2[100];

	expand(t1, t2);
	printf("%s", t2);
	getchar();
}

void expand(char s1[], char s2[])
{
	char c;
	int i, j;

	i = j = 0;
	while ((c = s1[i++]) != '\0') {
		if (s1[i] == '-' && s1[i + 1] >= c) {
			i++;
			while (c < s1[i]) {
				s2[j++] = c++;
			}
		}
		else {
			s2[j++] = c;
		}
	}
	s2[j] = '\0';
}
