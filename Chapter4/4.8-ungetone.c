#include <stdio.h>

char buff = 0;
int getch(void);
void ungetch(int c);

main()
{
	char c;

	c = getch();
	ungetch(c);
}

int getch(void)
{
	int tmp;

	if (buff != 0) {
		tmp = buff;
	}
	else {
		tmp = getchar();
	}
	buff = 0;
	return tmp;
}

void ungetch(int c)
{
	if (buff != 0) {
		printf("ungetch: Too many characters.\n");
	}
	else {
		buff = c;
	}
}
