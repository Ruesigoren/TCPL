#include <stdio.h>

/* 版本1 */
// void squeeze(char s[], int c);

/* 版本2 */
void squeeze(char s[], char t[]);

int main()
{
	char test[] = "ABCADAE";
	
	// squeeze(test, 'A');
	squeeze(test, "AE");
	printf("%s", test);
	getchar();
}

/* 版本1 */
// void squeeze(char s[], int c)
// {
	// int i, j;
	
	// for (i = 0, j = 0; s[i] != '\0'; ++i) {
		// if (s[i] != c) {
			// s[j++] = s[i];
		// }
	// }
	// s[j] = '\0';
// }

/* 版本2: 理解错了题意，本函数查找的是完全匹配的字符串，题目要求是匹配字符串中所有出现的字符 */
// void squeeze(char s1[], char s2[])
// {
	// int pos;
	// int i, j, k;
	
	// for (i = 0, j = 0, k = 0; s1[i] != '\0'; ++i) {
		// pos = i;//记录比对开始的位置
		// while (s1[i] == s2[k] && s1[i] != '\0') {
			// ++i;
			// ++k;
		// }
		// if (s2[k] != '\0') {
			// i = pos;//不匹配,恢复比对开始的位置
		// }
		// s1[j++] = s1[i];
		// k = 0;
	// }
	// s1[j] = '\0';
// }

/* 版本3 */
void squeeze(char s[], char t[])
{
	int i, j, k;
	
	for (i = 0, j = 0; s[i] != '\0'; i++) {
		for (k = 0; s[i] != t[k] && t[k] != '\0'; k++) {
			;
		}
		if (t[k] == '\0') {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}