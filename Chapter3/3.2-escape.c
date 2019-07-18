#include <stdio.h>

void escape(char s1[], char s2[]);
void unescape(char s1[], char s2[]);

main()
{
	char s1[] = "abcd\n\t1\32";
	char s2[100];
	char s3[100];

	escape(s1, s2);
	unescape(s2, s3);
}

void escape(char s1[], char s2[])
{
	int i, j;

	i = j = 0;
	while (s1[i] != '\0') {
		switch (s1[i])
		{
			case '\n':
				s2[j] = '\\';
				s2[++j] = 'n';
				break;
			case '\t':
				s2[j] = '\\';
				s2[++j] = 't';
				break;
			default:
				s2[j] = s1[i];
				break;
		}
		++i;
		++j;
	}
	s2[j] = '\0';
}

void unescape(char s1[], char s2[])
{
	int i, j;

	i = j = 0;
	while (s1[i] != '\0') {
		if (s1[i] == '\\') {
			switch (s1[++i])
			{
				case 'n':
					s2[j] = '\n';
					break;
				case 't':
					s2[j] = '\t';
					break;
				default:
					s2[j] = '\\';
					s2[++j] = s1[i];
					break;
			}
		}
		else {
			s2[j] = s1[i];
		}
		++i;
		++j;
	}
	s2[j] = '\0';
}
