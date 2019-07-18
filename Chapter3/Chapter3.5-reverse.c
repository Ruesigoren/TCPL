#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main()
{
	char test[] = "Hello World!";
	
	reverse(test);
	printf("%s", test);
	getchar();
}

/* 版本1 */
// void reverse(char s[])
// {
	// int i, j, temp;
	
	// for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		// temp = s[i];
		// s[i] = s[j];
		// s[j] = temp;
	// }
// }

/* 版本2 */
void reverse(char s[])
{
	int i, j, temp;
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		temp = s[i],	//逗号运算符
		s[i] = s[j],
		s[j] = temp;
	}
}