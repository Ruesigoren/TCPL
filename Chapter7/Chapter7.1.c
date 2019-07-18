#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int c;

	printf("%*.f", 4, 4.1);

	if (strcmp(argv[1], "lower") == 0) {
		while (( c = getchar()) != EOF) {
			putchar(tolower(c));
		}
	}
	else {
		while ((c = getchar()) != EOF) {
			putchar(toupper(c));
		}
	}
}