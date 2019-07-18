#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

int main()
{
	char test_1[] = "1-z,2-4-9,a-h,B-G";
	char test_2[100];
	
	expand(test_1, test_2);
	printf("%s", test_2);
	getchar();
}

void expand(char s1[], char s2[])
{
	int i, j, c;
	
	for (i = 0, j = 0; (c = s1[i]) != '\0'; i++) {
		if (isdigit(c)) {
			if (s1[i + 1] == '-' && isdigit(s1[i + 2]) && s1[i + 2] > c) {
				while (c < s1[i + 2]) {
					s2[j++] = c++;
				}
				i++;	//跳过 - 符号
			}
			else {
				s2[j++] = c;
			}
		}
		else if (islower(c)) {
			if (s1[i + 1] == '-' && islower(s1[i + 2]) && s1[i + 2] > c) {
				while (c < s1[i + 2]) {
					s2[j++] = c++;
				}
				i++;
			}
			else {
				s2[j++] = c;
			}
		}
		else if (isupper(c)) {
			if (s1[i + 1] == '-' && isupper(s1[i + 2]) && s1[i + 2] > c) {
				while (c < s1[i + 2]) {
					s2[j++] = c++;
				}
				i++;
			}
			else {
				s2[j++] = c;
			}
		}
		else {
			s2[j++] = c;
		}
	}
	s2[j] = '\0';
}