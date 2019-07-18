#include <stdio.h>

int htoi(char s[]);

int main()
{
	printf("%d\n", htoi("0XA1_0xA2"));
	getchar();
}

int htoi(char s[])
{
	int i;
	int HEX = 0;
	int value = 0;

	/* 这种写法默认输入是合法的, 但是假如输入 0x12 0x24 这种时, 其输出就不对了, 因此函数应该要在 HEX = 1时循环，在HEX = 0 时返回 */
	// for (i = 0; s[i] != '\0'; i++) {
		// if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')) {
			// HEX = 1;
			// i++;
		// }
		// else if (HEX) {
			// if (s[i] >= '0' && s[i] <= '9') {
				// value = 16 * value + s[i] - '0';
			// }
			// else if (s[i] >= 'A' && s[i] <= 'F') {
				// value = 16 * value + s[i] - 'A' + 10;
			// }
			// else if (s[i] >= 'a' && s[i] <= 'f') {
				// value = 16 * value + s[i] - 'A' + 10;
			// }
			// else {
				// HEX = 0;
			// }
		// }
	// }
	// return value;
	
	/* 修改后的写法 */
	i = 0;
	if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')) {
		HEX = 1;
		i += 2;
	}
	while (HEX) {
		if (s[i] >= '0' && s[i] <= '9') {
			value = 16 * value + s[i] - '0';
		}
		else if (s[i] >= 'A' && s[i] <= 'F') {
			value = 16 * value + s[i] - 'A' + 10;
		}
		else if (s[i] >= 'a' && s[i] <= 'f') {
			value = 16 * value + s[i] - 'A' + 10;
		}
		else {
			HEX = 0;
		}
		i++;
	}
	return value;
}