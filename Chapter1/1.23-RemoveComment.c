//#include <stdio.h>
//
//#define MAXLINE		100
//
//main()
//{
//	int i = 0, j = 0, pos = 0;
//	int line[MAXLINE];
//	int commentFlag = 0;
//	int Flag2 = 0;
//	//int Flag3 = 0;
//	int c, nc;
//
//	while ((c = getchar()) != EOF) {
//		line[i++] = c;
//		if (c == '\n') {
//			commentFlag = 0;
//			Flag2 = 0;
//			//Flag3 = 0;
//		}
//		//if (Flag3) {
//		//	if (c == '"') {
//		//		Flag3 = 0;
//		//		commentFlag = 0;
//		//		Flag2 = 0;
//		//	}
//		//	else {
//
//		//	}
//		//}
//		else if (commentFlag) {
//			if (c == '*') {
//				nc = getchar();
//				if (nc == '/') {
//					commentFlag = 0;
//				}
//				else {
//					ungetc(c, stdin);
//				}
//			}
//		}
//		else {
//			//if (c == '"') {
//			//	Flag3 = 1;
//			//}
//			if (c == '/') {
//				nc = getchar();
//				if (nc == '*') {
//					commentFlag = 1;
//				}
//				else if (nc == '/') {
//					Flag2 = 1;
//				}
//				else {
//					ungetc(c, stdin);
//				}
//			}
//			if (!Flag2 && !commentFlag) putchar(c);
//		}
//	}
//}

#include <stdio.h>

void rcomment(int c);
void in_comment(int ch);
void echo_quote(int c);

/* remove all comments from a valid C program */
main()
{
	int c, d;

	while ((c = getchar()) != EOF) {
		rcomment(c);
	}
	return 0;
}

/* rcomment: read each character, remove the comments */
void rcomment(int c)
{
	int d;

	if (c == '/') {
		if ((d = getchar()) == '*') {	/* beginning comment */
			in_comment('*');
		}
		else if (d == '/') {
			//putchar(c);					/* another slash */
			//rcomment(d);
			in_comment('/');
		}
		else {
			putchar(c);					/* not a comment */
			putchar(d);
		}
	}
	else if (c == '\'' || c == '"') {
		echo_quote(c);					/* quote begins */
	}
	else {
		putchar(c);						/* not a comment */
	}
}

/* in_comment: inside of a valid comment */
void in_comment(int ch)
{
	char line[100];
	int i = 0, j;
	int c, d;

	if (ch == '*') {
		line[0] = '/';
		line[1] = '*';
		c = getchar();
		line[2] = c;
		if (c == '\n') {
			for (j = 0; j < 3; ++j) {
				putchar(line[j]);
			}
			return;
		}
		d = getchar();
		line[3] = d;
		i = 4;
		while (1) {
			if (line[i - 1] == '/' && line[i - 2] == '/') {
				i = 2;
				for (j = 0; j < i; ++j) {
					putchar(line[j]);
				}
				while ((d = getchar()) != '\n')
					;
				putchar(d);
				break;
			}
			if (d == '\n') {
				for (j = 0; j < i + 1; ++j) {
					putchar(line[j]);
				}
				return;
			}
			if (c == '*' && d == '/') {
				break;
			}
			c = d;
			d = getchar();
			line[i++] = d;
		}
	}
	else if (ch == '/') {
		while (1) {
			d = getchar();
			if (d == '\n') {
				putchar(d);
				break;
			}
		}
		return;
	}
	//c = getchar();					/* prev character */
	//d = getchar();					/* curr character */
	//while (c != '*' || d != '/') {	/* search for end */
	//	c = d;
	//	d = getchar();
	//}
}

/* echo_quote: echo characters within quotes */
void echo_quote(int c)
{
	int d;
	char line[100];
	int i = 0, j;

	putchar(c);
	while (1) {
		d = getchar();
		line[i++] = d;
		if (d == c) {
			for (j = 0; j < i; ++j) {
				putchar(line[j]);
			}
			break;
		}
		if (d == '\n') {
			return;
		}
	}
	//while ((d = getchar()) != c) {		/* search for end */
	//	line[i] = d;
	//	putchar(d);
	//	if (d == '\\') {
	//		putchar(getchar());			/* ignore escape seq */
	//	}
	//}
	//putchar(d);
}
