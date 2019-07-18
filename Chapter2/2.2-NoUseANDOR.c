#include <stdio.h>

//main()
//{
//	int i;
//	int limit = 100;
//	int s[100];
//	int c;
//
//	//for (i = 0; i < limit - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
//	//	s[i] = c;
//	//}
//
//	for (i = 0; ; ++i) {
//		if (i >= limit - 1) {
//			return;
//		}
//		else if ((c = getchar()) == '\n') {
//			return;
//		}
//		else if (c == EOF) {
//			return;
//		}
//		s[i] = c;
//	}
//}

main()
{
	int i = 0;
	int limit = 100;
	int s[100];
	int c;
	enum loop { NO, YES };
	enum loop okloop = YES;

	while (okloop) {
		if (i >= limit - 1) {
			okloop = NO;
		}
		else if ((c = getchar()) == '\n') {
			okloop = NO;
		}
		else if (c == EOF) {
			okloop = NO;
		}
		else {
			s[i] = c;
			++i;
		}
	}
}
