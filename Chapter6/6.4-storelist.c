#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD		100
#define NDISTINCT	1000
#define BUFSIZE		100
char buf[BUFSIZE];
int bufp = 0;

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
void sortlist(void);
void treestore(struct tnode *);
char *Strdup(char *);
struct tnode *talloc(void);

struct tnode *list[NDISTINCT];
int ntn = 0;

main()
{
	struct tnode *root;
	char word[MAXWORD];
	int i;

	root = NULL;
	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			root = addtree(root, word);
		}
	}
	treestore(root);
	sortlist();
	for (i = 0; i < ntn; i++) {
		printf("%2d:%2s\n", list[i]->count, list[i]->word);
	}
	return 0;
}

void treestore(struct tnode *p)
{
	if (p != NULL) {
		treestore(p->left);
		if (ntn < NDISTINCT) {
			list[ntn++] = p;
		}
		treestore(p->right);
	}
}

void sortlist()
{
	int gap, i, j;
	struct tnode *temp;

	for (gap = ntn / 2; gap > 0; gap /= 2) {
		for (i = gap; i < ntn; i++) {
			for (j = i - gap; j >= 0; j -= gap) {
				if ((list[j]->count) >= (list[j + gap]->count)) {
					break;
				}
				temp = list[j];
				list[j] = list[j + gap];
				list[j + gap] = temp;
			}
		}
	}
}

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = Strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0) {
		p->count++;
	}
	else if (cond < 0) {
		p->left = addtree(p->left, w);
	}
	else {
		p->right = addtree(p->right, w);
	}
	return p;
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

struct tnode *talloc(void)
{
	return (struct tnode *)malloc(sizeof(struct tnode));
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
