#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN		1

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

#define HASHSIZE	101
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);
struct nlist *lookup(char *);
char *Strdup(char *);
struct nlist *install(char *, char *);
void undef(char *);

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++) {
		hashval = *s + 31 * hashval;
	}
	return hashval % HASHSIZE;
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