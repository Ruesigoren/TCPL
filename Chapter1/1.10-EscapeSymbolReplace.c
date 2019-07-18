#include <stdio.h>

/*将输入复制到输出，并把制表符替换为\t，回退符替换为\b，反斜杠替换为\\*/
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