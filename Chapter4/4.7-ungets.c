#include <stdio.h>
#include <string.h>

#define BUFSIZE		100

char buf[BUFSIZE];
int bufp = 0;
void ungetch(int c);
void ungets(char s[]);

main()
{
	char s[] = "hello world";

	ungets(s);
}

void ungetch(int c)
{
	if (bufp < BUFSIZE) {
		buf[bufp++] = c;
	}
	else {
		printf("Error; Buff is Full\n");
	}
}

void ungets(char s[])
{
	int len;

	len = strlen(s);
	while (len-- > 0) {
		ungetch(s[len]);
	}
}
