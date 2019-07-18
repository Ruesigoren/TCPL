#include <stdio.h>
#include <string.h>

#define MAXLINE          1000

int Getline(char *line, int max);

/* cmd 切换到本程序的 exe 文件 所在目录之后，比如用Test_002 12 来查找12 ，此时可以输入，只要输入的内容包含12，就会相应地打印出来 */
//main(int argc, char *argv[])
//{
//	char line[MAXLINE];
//	int found = 0;
//
//	if (argc != 2) {
//		printf("Usage: find pattern\n");
//	}
//	else {
//		while (Getline(line, MAXLINE) > 0) {
//			if (strstr(line, argv[1]) != NULL) {
//				printf("%s", line);
//				found++;
//			}
//		}
//	}
//	return found;
//}

main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-') {
		while (c = *++argv[0]) {
			switch (c)
			{
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
		}
	}
	if (argc != 1) {
		printf("Usage: find -x -n pattern\n");
	}
	else {
		while (Getline(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number) {
					printf("%ld:", lineno);
				}
				printf("%s", line);
				found++;
			}
		}
	}
	return found;
}

int Getline(char *line, int max)
{
	int c;
	char *p = line;

	while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
		*line++ = c;
	}
	if (c == '\n') {
		*line++ = c;
	}
	*line = '\0';
	return line - p;
}
