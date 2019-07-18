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
void errmsg(char *s);

int gettoken(void);
int getch(void);
void ungetch(int c);


int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
int prevtoken = NO;

//test 
//input: 
//void *(*comp)(int *, char *, int(*fnc)())
//ouput:
//comp:  pointer to function expecting pointer to int, pointer to char, pointer to function returning int and returning  pointer to void

main()
{
	while (gettoken() != EOF) {
		strcpy_s(datatype, MAXTOKEN, token);
		out[0] = '\0';
		dcl();
		if (tokentype != '\n') {
			printf("syntax error\n");
		}
		printf("%s: %s %s\n", name, out, datatype);
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
		strcat_s(out, 1000, " pointer to");
	}
}

void dirdcl(void)
{
	int type;
	void parmdcl(void);

	if (tokentype == '(') {
		dcl();
		if (tokentype != ')') {
			//printf("erroe: missing ) \n");
			errmsg("erroe: missing ) \n");
		}
	}
	else if (tokentype == NAME) {
		if (name[0] == '\0') {
			strcpy_s(name, MAXTOKEN, token);
		}
	}
	else {
		prevtoken = YES;
	}
	while ((type = gettoken()) == PARENS || type == BRACKETS
		|| type == '(') {
		if (type == PARENS) {
			strcat_s(out, 1000, " function returning");
		}
		else if (type == '(') {
			strcat_s(out, 1000, " function expecting");
			parmdcl();
			strcat_s(out, 1000, " and returning ");
		}
		else {
			strcat_s(out, 1000, " array ");
			strcat_s(out, 1000, token);
			strcat_s(out, 1000, " of");
		}
	}
}

void errmsg(char *msg)
{
	printf("%s", msg);
	prevtoken = YES;
}
