#include <stdio.h>

#define NONBLANK		'A'

/*将输入复制到输出，并将相连的多个空格用一个空格替代*/
main()
{
	/* 第一种实现*/
	//int blankFlag = 0;
	//int c;

	//while((c = getchar()) != EOF){ 
	//	if (c == ' ' && blankFlag == 0) {
	//		putchar(c);
	//		blankFlag = 1;
	//	}
	//	else if (c != ' ') {
	//		putchar(c);
	//		blankFlag = 0;
	//	}
	//}

	/*第二种实现*/
	// int c, lastc;

	// lastc = 1;	//随便一个非空格字符(空格的ASCII码为32)
	// while ((c = getchar()) != EOF) {
		// if (c != ' ')
			// putchar(c);
		// else if (lastc != ' ')
			// putchar(c);
		// lastc = c;
	// }
	
	/* 第三种实现 */
	// int c, lastc;
	
	// lastc = NONBLANK;
	// while ((c = getchar()) != EOF) {
		// if (c != ' ') {
			// putchar();
		// }
		// if (c == ' ') {
			// if (lastc != ' ') {
				// putchar(c);
			// }
		// }
		// lastc = c;
	// }
	
	/* 第四种实现 */
	int c, lastc;
	
	lastc = NONBLANK;
	while ((c = getchar()) != EOF) {
		if(c != ' ' || lastc != ' ') {
			putchar(c);
		}
		lastc = c;
	}
}