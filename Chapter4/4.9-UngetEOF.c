#include <stdio.h>
#include <string.h>

#define BUFSIZE		100

int buf[BUFSIZE];
int bufp = 0;
int getch(void);
void ungetch(int c);

main()
{
	char s[] = "hello world";

	ungets(s);
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
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
