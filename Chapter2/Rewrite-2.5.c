#include <stdio.h>

int any(char s[], char t[]);

int main()
{
	char s[] = "Hello World!";
	char t[] = "lo";
	
	printf("%d\n", any(s, t));
	getchar();
}

/* 版本1: 符合题意的版本, 查找 t 中任意字符在 s 中第一次出现的位置 */
// int any(char s[], char t[])
// {
	// int i, j;
	
	// for (i = 0; s[i] != '\0'; i++) {
		// for (j = 0; t[j] != '\0'; j++) {
			// if (s[i] == t[j]) {
				// return i;
			// }
		// }
	// }
	// return -1；
// }

/* 版本2: 查找 t 在 s 中出现的位置 */
int any(char s[], char t[])
{
	int i, j, k;
	
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++) {
			;
		}
		if (k > 0 && t[k] == '\0') {
			return i;
		}
	}
	return -1;
}