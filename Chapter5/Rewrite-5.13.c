#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH				100

int Getline(char line[], int max);

#define DEFAULT_PRINT_LINE_NUM		3
#define MAX_PRINT_LINE_NUM			10

int main(int argc, char *argv[])
{
	int print_line_num;
	
	/* 读取命令行参数 */
	if (argc == 1) {
		print_line_num = DEFAULT_PRINT_LINE_NUM;
	}
	else if (argc == 2 && (*++argv)[0] == '-') {
		print_line_num = atoi(argv[0] + 1);
	}
	else {
		printf("error: usage tail [-n]\n");
		exit(1);
	}
	/* 错误处理 */
	if (print_line_num < 1 || print_line_num > MAX_PRINT_LINE_NUM) {
		print_line_num = MAX_PRINT_LINE_NUM;
	}
	
	/* 初始化存储数组 */
	char *lineptr[MAX_PRINT_LINE_NUM];
	int i;
	
	for (i = 0; i < MAX_PRINT_LINE_NUM; i++) {
		lineptr[i] = NULL;
	}
	
	/* 分配存储空间 */
	char *p, *buf, *bufend;
	
	p = buf = (char *)malloc(MAX_PRINT_LINE_NUM * MAX_LINE_LENGTH);
	/* 错误处理 */
	if (p == NULL) {
		printf("Can't allocate memory\n");
		exit(1);
	}
	bufend = buf + MAX_PRINT_LINE_NUM * MAX_LINE_LENGTH;
	
	/* 读取输入行 */
	int len;
	int nlines = 0;
	int lastline = 0;
	char line[MAX_LINE_LENGTH];
	
	while ((len = Getline(line, MAX_LINE_LENGTH)) > 0) {
		if (p + len + 1 > bufend) {
			p = buf;
		}
		strcpy(p, line);
		lineptr[lastline++] = p;
		if (lastline > MAX_PRINT_LINE_NUM) {
			lastline = 0;
		}
		p += len + 1;
		nlines++;
	}
	
	/* 输出最后 print_line_num 行 */
	int firstline;
	
	if (print_line_num > nlines) {
		print_line_num = nlines;
	}
	firstline = lastline - print_line_num;
	if (firstline < 0) {
		firstline += MAX_PRINT_LINE_NUM;
	}
	for (i = firstline; print_line_num-- > 0; i = (i + 1) % MAX_PRINT_LINE_NUM) {
		printf("%s", lineptr[i]);
	}
	getchar();
	return 0;
}

int Getline(char line[], int max)
{
	int c;
	int i;
	
	i = 0;
	while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
		line[i++] = c;
	}
	if (c == '\n') {
		line[i++] = c;
	}
	line[i] = '\0';
	return i;
}