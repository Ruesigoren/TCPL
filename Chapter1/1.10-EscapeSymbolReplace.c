#include <stdio.h>

/*�����븴�Ƶ�����������Ʊ���滻Ϊ\t�����˷��滻Ϊ\b����б���滻Ϊ\\*/
main()
{
	int c;

/*1*/
	// while ((c = getchar()) != EOF) {
		// if (c == '\t') {
			// printf("\\t");
			// //putchar('\\');
			// //putchar('t');
		// }
		// else if (c == '\b') {
			// printf("\\b");
			// // putchar('\\');
			// // putchar('b');
		// }
		// else if (c == '\\') {
			// printf("\\\\");
			// // putchar('\\');
			// // putchar('\\');
		// }
		// else
			// putchar(c);
	// }
	
/*2*/	
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			printf("\\t");
		}
		if (c == '\b') {
			printf("\\b");
		}
		if (c == '\\') {
			printf("\\\\");
		}
		if (c != '\t') {
			if (c != '\b') {
				if (c != '\\') {
					putchar(c);
				}
			}
		}
	}
}