#include <stdio.h>

void strncpy(char *s1, char *s2, int n);
void strncat(char *s1, char *s2, int n);
int strncmp(char *s1, char *s2, int n);

main()
{
	char s1[40];
	char s2[] = "hello world!";

	strncpy(s1, s2, 10);
	printf("%s\n", s1);
	strncat(s1, s2, 10);
	printf("%s\n", s1);
	printf("%d\n", strncmp(s1, s2, 5));
}

void strncpy(char *s1, char *s2, int n)
{
	//while (n-- > 0) {
	//	*s1++ = *s2++;
	//	if (*s2 == '\0') {
	//		break;
	//	}
	//}
	while (*s2 && n-- > 0) {
		*s1++ = *s2++;
	}
	*s1 = '\0';
	//while (n-- > 0) {		//���е�д��Ҳ�Ǵ���©����,���粻��ȫ����s2�Ļ�,���մ𰸵�д��,s1��ĩβ��û��'\0'��������
	//	*s1++ = '\0';
	//}
	//if (n > 0) {
	//	*s1 = '\0';
	//}
}

void strncat(char *s1, char *s2, int n)
{
	while (*s1) {
		s1++;
	}
	while (*s2 && n-- > 0) {
		*s1++ = *s2++;
	}
	*s1 = '\0';
}

int strncmp(char *s1, char *s2, int n)
{
	//while (n-- > 0) {
	//	while (*s1++ == *s2++) {
	//		if (*s1 == '\0' || *s2 == '\0') {
	//			return 0;
	//		}
	//	}
	//}
	//return *s1 - *s2;
	for (; *s1 == *s2; s1++, s2++) {
		if (n-- == 0 || *s1 == '\0' || *s2 == '\0') {
			return 0;
		}
	}
	return *s1 - *s2;
}
