#include <stdio.h>
/* copy input to output; 1st version */
main()
{
	int c;

	//c = getchar();
	//while (c != EOF) {	//Windows下 按 Ctrl + Z 输入EOF
	//	putchar(c);
	//	c = getchar();
	//}
	//printf("%d\n", EOF);


	// while ((c = getchar()) != EOF) {	//getchar() 每次读入一个字符,回车也作为字符被读入。因此输入1，会打印出两行1
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