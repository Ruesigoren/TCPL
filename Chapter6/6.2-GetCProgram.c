#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD		100
#define YES			1
#define NO			0
#define BUFSIZE		100
char buf[BUFSIZE];
int bufp = 0;

struct tnode
{
	char *word;
	int match;
	struct tnode *left;
	struct tnode *right;
};

int compare(char *s, struct tnode *, int, int *);
struct  tnode *addtreex(struct tnode *, char *, int, int *);
void treexprint(struct  tnode *);
int getword(char *, int);

int main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	int found = NO;
	int num;

	num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 6;
	root = NULL;
	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0]) && strlen(word) >= num) {
			root = addtreex(root, word, num, &found);
		}
	}
	treexprint(root);
	return 0;
}

struct tnode *talloc(void);
char *Strdup(char *);

struct tnode *addtreex(struct tnode *p, char *w, int num, int *found)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = Strdup(w);
		p->match = *found;
		p->left = p->right = NULL;
	}
	else if ((cond = compare(w, p, num, found)) < 0) {
		p->left = addtreex(p->left, w, num, found);
	}
	else if (cond > 0) {
		p->right = addtreex(p->right, w, num, found);
	}
	return p;
}

int compare(char *s, struct tnode *p, int num, int *found)
{
	int i;
	char *t = p->word;

	for (i = 0; *s == *t; i++, s++, t++) {
		if (*s == '\0') {
			return 0;
		}
	}
	if (i >= num) {
		*found = YES;
		p->match = YES;
	}
	return *s - *t;
}

void treexprint(struct tnode *p)
{
	if (p != NULL)
	{
		treexprint(p->left);
		if (p->match) {
			printf("%s\n", p->word);
		}
		treexprint(p->right);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *Strdup(char *s)
{
	char *p;

	p = (char *)malloc(strlen(s) + 1);
	if (p != NULL) {
		strcpy_s(p, strlen(s) + 1, s);		//caution!	strlen(s) + 1
	}
	return p;
}

int getword(char *word, int lim)
{
	int c, d, comment(void), getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch())) {
		;
	}
	if (c != EOF) {
		*w++ = c;
	}
	if (isalpha(c) || c == '_' || c == '#') {
		for (; --lim > 0; w++) {
			if (!isalnum(*w = getch()) && *w != '_') {
				ungetch(*w);
				break;
			}
		}
	}
	else if (c == '\'' || c == '"') {
		for (; --lim > 0; w++) {
			if ((*w = getch()) == '\\') {
				*++w = getch();
			}
			else if (*w == c) {
				w++;
				break;
			}
			else if (*w == EOF) {
				break;
			}
		}
	}
	else if (c == '/') {
		if ((d = getch()) == '*') {
			c = comment();
		}
		else {
			ungetch(d);
		}
	}
	*w = '\0';
	return c;
}

int comment(void)
{
	int c;

	while ((c = getch()) != EOF) {
		if (c == '*') {
			if ((c = getch()) == '/') {
				break;
			}
			else {
				ungetch(c);
			}
		}
	}
	return c;
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
