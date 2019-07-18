#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD		100
#define BUFSIZE		100
char buf[BUFSIZE];
int bufp = 0;
//typedef int(* PFI)(char *, char *);
//PFI numcmp;
//
//PFI numcmp(char *s, char *t)
//{
//
//}
struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

#define HASHSIZE	101
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);
void error(int, char *);
int getch(void);
void getdef(void);
int getword(char *, int);
struct nlist *install(char *, char *);
struct nlist *lookup(char *);
void skipblanks(void);
void undef(char *);
void ungetch(int);
void ungets(char *);

main()
{
	char w[MAXWORD];
	struct nlist *p;

	while (getword(w, MAXWORD) != EOF) {
		if (strcmp(w, "#") == 0) {
			getdef();
		}
		else if (!isalpha(w[0])) {
			printf("%s", w);
		}
		else if ((p = lookup(w)) == NULL) {
			printf("%s", w);
		}
		else {
			ungets(p->defn);
		}
	}
	return 0;
}

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++) {
		hashval = *s + 31 * hashval;
	}
	return hashval % HASHSIZE;
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

void getdef(void)
{
	int c, i;
	char def[MAXWORD], dir[MAXWORD], name[MAXWORD];

	skipblanks();
	if (!isalpha(getword(dir, MAXWORD))) {
		error(dir[0],
			"getdef: expecting a directive after #");
	}
	else if (strcmp(dir, "define") == 0) {
		skipblanks();
		if (!isalpha(getword(name, MAXWORD))) {
			error(name[0],
				"getdef: non-aplha - name expected");
		}
		else {
			skipblanks();
			for (i = 0; i < MAXWORD - 1; i++) {
				if ((def[i] = getch()) == EOF ||
					def[i] == '\n') {
					break;
				}
				def[i] = '\0';
				if (i <= 0) {
					error('\n', "getdef: incomplete define");
				}
				else {
					install(name, def);
				}
			}
		}
	}
	else if (strcmp(dir, "undef") == 0) {
		skipblanks();
		if (!isalpha(getword(name, MAXWORD))) {
			error(name[0], "getdef: non-alpha in undef");
		}
		else {
			undef(name);
		}
	}
	else {
		error(dir[0],
			"getdef: expecting a directive after #");
	}
}

void undef(char *s)
{
	int h;
	struct nlist *prev, *np;

	prev = NULL;
	h = hash(s);
	for (np = hashtab[h]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0) {
			break;
		}
		prev = np;
	}
	if (np != NULL) {
		if (prev = NULL) {
			hashtab[h] = np->next;
		}
		else {
			prev->next = np->next;
		}
		free((void *)np->name);
		free((void *)np->defn);
		free((void *)np);
	}
}

void error(int c, char *s)
{
	printf("error: %s\n", s);
	while (c != EOF && c != '\n') {
		c = getch();
	}
}

void skipblanks(void)
{
	int c;

	while ((c = getch()) == ' ' || c == '\t') {
		;
	}
	ungetch(c);
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

void ungets(char *s)
{
	int len;

	len = strlen(s);
	while (len-- > 0) {
		ungetch(s[len]);
	}
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0) {
			return np;
		}
	}
	return NULL;
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

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *)malloc(sizeof(*np));
		if (np == NULL || (np->name = Strdup(name)) == NULL) {
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else {
		free((void *)np->defn);
	}
	if ((np->defn = Strdup(defn)) == NULL) {
		return NULL;
	}
	return np;
}
