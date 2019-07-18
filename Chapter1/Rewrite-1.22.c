#include <stdio.h>

#define TABSIZE			8

char line[TABSIZE + 1];
int pos;

int findblank(int p);
void printline(int p);

int main()
{
	int c;
	int p;
	
	pos = 1;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			line[pos] = c;
			p = findblank(pos);
			printline(p);
			pos = 0;
		}
		else {
			line[pos] = c;
			if (c == '\n' || pos % TABSIZE == 0) {
				p = findblank(pos);
				printline(p);
				pos = 0;
			}
		}
		pos++;
	}
}

int findblank(int p)
{
	int i;
	
	i = p;
	while (line[i] == '\t' || line[i] == ' ' || line[i] == '\n') {
		i--;
	}
	return i;
}

void printline(int p)
{
	int i;
	
	for (i = 1; i <= p; ++i) {
		putchar(line[i]);
	}
	putchar('\n');
}