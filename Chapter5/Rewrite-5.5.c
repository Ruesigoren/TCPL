#include <stdio.h>

void u_strncpy(char *s1, char *s2, int n);
void u_strncat(char *s1, char *s2, int n);
int u_strncmp(char *s1, char *s2, int n);

int main()
{
	char s1[] = "orld!";
	char s2[] = "world!";
	
	printf("%d\n", u_strncmp(s1, s2, 1));
	u_strncpy(s2, s1, 3);
	printf("%s\n", s2);
	u_strncat(s2, s1, 6);
	printf("%s\n", s2);
	getchar();
}

void u_strncpy(char *s1, char *s2, int n)
{
	for (; n > 0 && *s2 ; n--) {
		*s1++ = *s2++;
	}
	*s1 = '\0';
}

void u_strncat(char *s1, char *s2, int n)
{
	for (; *s1; s1++) {
		;
	}
	for (; n > 0 && *s2; n--) {
		*s1++ = *s2++;
	}
	*s1 = '\0';
}

int u_strncmp(char *s1, char *s2, int n)
{
	for (; *s1 == *s2; s1++, s2++) {
		if (n-- <= 0 || *s1 == '\0' || *s2 == '\0') {
			return 0;
		}
	}
	return *s1 - *s2;
}