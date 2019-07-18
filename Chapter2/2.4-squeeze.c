#include <stdio.h>

int isSame(char s1[], char s2[], int pos);
//void squeeze(char s1[], char s2[]);
void squeeze(char s1[], char s2[]);
int strlen(char s[]);

main()
{
	char s1[] = "asdfsfsfsf";
	char s2[] = "fs";
	
	squeeze(s1, s2);
	printf("%s\n", s1);
}

//void squeeze(char s1[], char s2[])
//{
//	int i = 0, j = 0;
//	int len;
//
//	len = strlen(s2);
//	while (s1[i] != '\0') {
//		s1[j] = s1[i];
//		if (s1[i] == s2[0]) {
//			if (isSame(s1, s2, i)) {
//				i += len;
//			}
//			else {
//				++i;
//				++j;
//			}
//		}
//		else {
//			++i;
//			++j;
//		}
//	}
//	s1[j] = '\0';
//}

int isSame(char s1[], char s2[], int pos)
{
	int i = 0;

	while (s1[pos + i] != '\0' && s2[i] != '\0') {
		if (s1[pos + i] != s2[i]) {
			return 0;
		}
		++i;
	}
	if (s2[i] == '\0') {
		return 1;
	}
	return 0;
}

int strlen(char s[])
{
	int i = 0;

	while (s[i] != '\0') {
		++i;
	}
	return i;
}

void squeeze(char s1[], char s2[])
{
	int i, j, k;

	for (i = k = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; ++j) {
			;
		}
		if (s2[j] == '\0') {
			s1[k++] = s1[i];
		}
	}
	s1[k] = '\0';
}
