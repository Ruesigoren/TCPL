#include <stdio.h>

#define NONBLANK		'A'

/*�����븴�Ƶ���������������Ķ���ո���һ���ո����*/
main()
{
	/* ��һ��ʵ��*/
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

	/*�ڶ���ʵ��*/
	// int c, lastc;

	// lastc = 1;	//���һ���ǿո��ַ�(�ո��ASCII��Ϊ32)
	// while ((c = getchar()) != EOF) {
		// if (c != ' ')
			// putchar(c);
		// else if (lastc != ' ')
			// putchar(c);
		// lastc = c;
	// }
	
	/* ������ʵ�� */
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
	
	/* ������ʵ�� */
	int c, lastc;
	
	lastc = NONBLANK;
	while ((c = getchar()) != EOF) {
		if(c != ' ' || lastc != ' ') {
			putchar(c);
		}
		lastc = c;
	}
}