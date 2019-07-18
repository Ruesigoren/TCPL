#include <stdio.h>
#include <string.h>

#define MAXLINE		1000		/* maxmium input size */

int getline(char line[], int maxline);
//void reverse(char line[], char rvs[]);
void reverse(char line[]);

/* print longest input line */
main()
{
	int len;
	int max;
	char line[MAXLINE];
	//char rvs[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) {
		//reverse(line, rvs);
		reverse(line);
		printf("%s", line);
	}
	return 0;
}

int getline(char line[], int maxline)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < maxline - 2) {
			line[j] = c;
			++j;
		}
	}
	if (c == '\n') {
		line[j] = c;
		++i;
		++j;
	}
	line[j] = '\0';
	return i;
}

/* 我的实现 */
//void reverse(char line[], char rvs[])
//{
//	int i = 0, j = 0;
//
//	while (line[i] != '\0')
//		++i;
//	--i;
//	if (line[i] == '\n')
//		--i;
//	while (i >= 0) {
//		rvs[j] = line[i];
//		++j;
//		--i;
//	}
//	rvs[j] = '\n';
//	++j;
//	rvs[j] = '\0';
//}

/* 第二种实现 */
void reverse(char line[])
{
	int i, j, temp;
	
	i = j = 0;
	while (line[i] != '\0')
		++i;
	--i;
	if (line[i] == '\n')
		--i;
	while (j < i) {
		temp = line[j];
		line[j] = line[i];
		line[i] = temp;
		++j;
		--i;
	}

}