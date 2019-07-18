#include <stdio.h>

#define TABSIZE			8

int main()
{
	int pos;
	int nblank = 0;
	int ntab = 0;
	int c;
	
	for (pos = 1; (c = getchar()) != EOF; ++pos) {
		if (c == ' ') {
			if (pos % TABSIZE == 0) {
				++ntab;
				nblank = 0;
				pos = 0;
			}
			else {
				nblank++;
			}
		}
		/* Debug: 非空格字符之前都要输出所有的 TAB 和空格符, 所以这部分代码需要放在 else 分支里面 */
		// else if (c == '\n') {
			// pos = 0;
			// putchar(c);
		// }
		else {
			while (ntab > 0) {
				putchar('\t');
				ntab--;
			}
			if (c == '\t') {		/* 空格之后遇到TAB 用一个TAB 替代即可 */
				nblank = 0;
				pos = 0;
			}
			else {
				while (nblank > 0) {
					putchar(' ');
					nblank--;
				}
			}
			if (c == '\n') {
				pos = 0;
			}
			putchar(c);
		}
	}
	/* test */
	// for (pos = 1; pos < 100; pos++) {
		// pos = pos + (TABSIZE - (pos - 1) % TABSIZE) - 1;
		// printf("%d\n", pos);
	// }
	// getchar();
}