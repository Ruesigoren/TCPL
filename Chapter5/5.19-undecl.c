#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define	MAXTOKEN	100
#define BUFSIZE		100

char buf[BUFSIZE];
int bufp = 0;

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int nexttoken(void);
int getch(void);
void ungetch(int c);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
int prevtoken = NO;

main()
{
	int type;
	char temp[MAXTOKEN];

	while (gettoken() != EOF) {
		strcpy_s(out, MAXTOKEN, token);
		while ((type = gettoken()) != '\n') {
			if (type == PARENS || type == BRACKETS) {
				strcat_s(out, MAXTOKEN, token);
			}
			else if (type == '*') {
				if ((type == nexttoken()) == PARENS ||
					type == BRACKETS) {
					sprintf_s(temp, MAXTOKEN, "(*%s)", out);
				}
				else {
					sprintf_s(temp, MAXTOKEN, "*%s", out);
				}
				strcpy_s(out, MAXTOKEN, temp);
			}
			else if (type == NAME) {
				sprintf_s(temp, MAXTOKEN, "%s %s", token, out);
				strcpy_s(out, MAXTOKEN, temp);
			}
			else {
				printf("invalid input at %s\n", token);
			}
		}
		printf("%s\n", out);
	}
	return 0;
}

int gettoken(void)
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	if (prevtoken == YES) {
		prevtoken = NO;
		return tokentype;
	}
	while ((c = getch()) == ' ' || c == '\t') {
		;
	}
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy_s(token, MAXTOKEN, "()");
			return tokentype = PARENS;
		}
		else {
			ungetch(c);
			return tokentype = '(';
		}
	}
	else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; ) {
			;
		}
		*p = '\0';
		return tokentype = BRACKETS;
	}
	else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch());) {
			*p++ = c;
		}
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	}
	else {
		return tokentype = c;
	}
}

int nexttoken(void)
{
	int type;
	extern int prevtoken;

	type = gettoken();
	prevtoken = YES;
	return type;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp < BUFSIZE) {
		buf[bufp++] = c;
	}
	else {
		printf("Error; Buff is Full\n");
	}
}


void dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*'; ) {
		ns++;
	}
	dirdcl();
	while (ns-- > 0) {
		strcat_s(out, MAXTOKEN, " pointer to");
	}
}

void dirdcl(void)
{
	int type;

	if (tokentype == '(') {
		dcl();
		if (tokentype != ')') {
			printf("erroe: missing ) \n");
		}
	}
	else if (tokentype == NAME) {
		strcpy_s(name, MAXTOKEN, token);
	}
	else {
		printf("error: expected name or (dcl)\n");
	}
	while ((type = gettoken()) == PARENS || type == BRACKETS) {
		if (type == PARENS) {
			strcat_s(out, 19, "function returning");
		}
		else {
			strcat_s(out, MAXTOKEN, " array ");
			strcat_s(out, MAXTOKEN, token);
			strcat_s(out, MAXTOKEN, " of");
		}
	}
}

void errmsg(char *msg)
{
	printf("%s", msg);
	prevtoken = YES;
}
