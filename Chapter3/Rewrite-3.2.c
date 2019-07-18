#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
	
}

/* 使用此函数应该注意目标数组 t 的大小，当心溢出 */
void escape(char s[], char t[])
{
	int i, j;
	
	for (i = j = 0; s[i] != '\0'; ++i, ++j) {
		switch (s[i]) {
		case '\n':
			t[j] = '\\';
			t[++j] = 'n';
			break;
		case '\t':
			t[j] = '\\';
			t[++j] = 't';
			break;
		default:
			t[j] = s[i];
			break;
		}
	}
	t[j] = '\0';
}

void unescape(char s[], char t[])
{
	int i, j;
	
	for (i = j = 0; s[i] != '\0'; ++i, ++j) {
		if (s[i] == '\\') {
			switch (s[i + 1]) {
			case 'n':
				t[j] = '\t';
				break;
			case 't':
				t[j] = '\n';
				break;
			default:
				t[j] = s[i];
				t[++j] = s[++i];
				break;
		}
		else {
			t[j] = s[i];
		}
	}
	t[j] = '\0';
}