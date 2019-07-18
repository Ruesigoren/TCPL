#include <stdio.h>
#include <string.h>

int trim(char s[]);
int found(char s1[], char s2[]);

int main()
{
	char test_1[] = "Hello World!";
	char test_2[] = "M";
	
	printf("%d", found(test_1, test_2));
	getchar();
}

int trim(char s[])
{
	int i;
	
	for (i = strlen(s) - 1; i >= 0; i--) {
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
			break;
		}
	}
	s[i + 1] = '\0';
	return i;
}

/* 版本1 */
int found(char s1[], char s2[])
{
	int i, j;
	
	for (i = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j]) {
				goto found;
			}
		}
	}
	return -1;
found:
	return 1;
}

/* 版本2 */
// int found(char s1[], char s2[])
// {
	// int i, j;
	// int found = 0;
	
	// for (i = 0; s1[i] != '\0' && !found; i++) {
		// for (j = 0; s2[j] != '\0' && !found; j++) {
			// if (s1[i] == s2[j]) {
				// found = 1;
			// }
		// }
	// }
	// if (found) {
		// return 1;
	// }
	// else {
		// return -1;
	// }
// }