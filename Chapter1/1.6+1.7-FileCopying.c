#include <stdio.h>
/* copy input to output; 1st version */
main()
{
	int c;

	//c = getchar();
	//while (c != EOF) {	//Windows�� �� Ctrl + Z ����EOF
	//	putchar(c);
	//	c = getchar();
	//}
	//printf("%d\n", EOF);


	// while ((c = getchar()) != EOF) {	//getchar() ÿ�ζ���һ���ַ�,�س�Ҳ��Ϊ�ַ������롣�������1�����ӡ������1
		// printf("%d\n", c);
	// }
	// printf("%d - at EOF\n", c);
	// getchar();
	
	
	/* word count version 1 */
	// c = 0;
	// while (getchar() != EOF) {
		// ++c;
	// }
	// printf("%d\n", c);
	// getchar();
	
	
	/* word count version 2 */
	for(c = 0; getchar() != EOF; c++) {
		;
	}
	printf("%d\n", c);
	getchar();
}