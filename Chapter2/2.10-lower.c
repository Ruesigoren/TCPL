#include <stdio.h>

char lower(char c);

main()
{
	printf("%c\n",lower('A'));
	printf("%d", 3 + 2 >> 1);
	getchar();
}

char lower(char c)
{
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}