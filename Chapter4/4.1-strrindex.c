#include <stdio.h>
#include <string.h>

int strrindex(char s1[], char s2[]);

main()
{
	char s[] = "hello world";
	char t[] = "ll";

	printf("%d\n", strrindex(s, t));
	getchar();
}

//int strrindex(char s1[], char s2[])
//{
//	int i, j, k;
//	int pos = -1;
//
//	for (i = 0; s1[i] != '\0'; ++i) {
//		for (j = i, k = 0; s2[k] != '\0' && s2[k] == s1[j]; ++j, ++k) {
//			;
//		}
//		if (k > 0 && s2[k] == '\0') {
//			pos = i;
//		}
//	}
//	return pos;
//}

/* 下面是错误写法 */
// int strrindex(char s1[], char s2[])
// {
	// int i, j, k;
	// int s;
	
	// s = strlen(s1) - strlen(s2);
	// for (i = s; i >= 0; --i) {
		// for (j = i, k = 0; s2[k] != '\0' && s2[k] == s1[j]; ++j, ++k) {
			// ;
		// }
		// if (k > 0 && s2[k] == '\0') {
			// return i;
		// }
	// }
	// return -1;
// }

int strrindex(char s1[], char s2[]) 
{
	int i, j, k, s, pos;
	
	pos = -1;
	s = strlen(s1) - strlen(s2);
	if (s < 0) {
		return pos;
	}
	for (i = 0; i <= s; ++i) {
		for (j = i, k = 0; s2[k] != '\0' && s1[j] == s2[k]; ++j, ++k) {
			;
		}
		if (k > 0 && s2[k] == '\0') {
			pos = i;
		}
	}
	return pos;
}