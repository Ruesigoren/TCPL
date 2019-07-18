#include <stdio.h>

#define TABSIZE		8	//1个TAB = 8个空格

int main()
{
	int pos;
	int c;
	int nblank;
	
	pos = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			nblank = TABSIZE - pos % TABSIZE;
			while (nblank > 0) {
				putchar(' ');
				nblank--;
			}
			pos = 0;
		}
		else if (c == '\n') {
			pos = 0;
			putchar(c);
		}
		else {
			++pos;
			putchar(c);
		}
	}
	getchar();
}