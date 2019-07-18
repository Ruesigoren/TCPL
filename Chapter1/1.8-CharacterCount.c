#include <stdio.h>

/* count characters in input; 2nd version */
main()
{
	//double nc;

	//for (nc = 0; getchar() != EOF; ++nc)
	//	;
	//printf("%.0f\n", nc);	//%.0f 表示不打印出小数点以及小数部分
	
	/* line count */
	// int c, nl;
	
	// nl = 0;
	// while ((c = getchar()) != EOF) {
		// if (c == '\n') {
			// ++nl;
		// }
	// }
	// printf("%d lines\n", nl);

	long c, n1, n2, n3;

	n1 = n2 = n3 = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++n1;
		else if (c == '\t')
			++n2;
		else if (c == '\n')
			++n3;
	}
	printf("Blanks -- %ld\n", n1);
	printf("Tabs -- %ld\n", n2);
	printf("Enters -- %ld\n", n3);
	getchar();
}