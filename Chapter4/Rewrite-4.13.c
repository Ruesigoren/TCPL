#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void rever(char s[], int start, int stop);

int main()
{
	char s[] = "hello world";
	
	reverse(s);
	printf("%s", s);
	getchar();
}

void reverse(char s[])
{
	rever(s, 0, strlen(s) - 1);
}

void rever(char s[], int start, int stop)
{
	int c;
	
	if (start < stop) {
		c = s[start];
		s[start] = s[stop];
		s[stop] = c;
		rever(s, start + 1, stop - 1);
	}
}