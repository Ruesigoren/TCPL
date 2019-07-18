#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

#define HASHSIZE			101

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *name, char *defn);

int main()
{
	struct nlist *p;
	
	install("HASHSIZE", "101");
	install("IN", "1");
	install("OUT", "0");
	p = lookup("HASHSIZE");
	printf("%s\n", p->defn);
	getchar();
}


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

char *u_strdup(char *);

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	
	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *)malloc(sizeof(*np));
		if (np == NULL || (np->name = u_strdup(name)) == NULL) {
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else {
		free((void *)np->defn);
	}
	if ((np->defn = u_strdup(defn)) == NULL) {
		return NULL;
	}
	return np;
}

char *u_strdup(char *s)
{
	char *p;
	
	p = (char *)malloc(strlen(s) + 1);
	if (p != NULL) {
		strcpy(p, s);
	}
	return p;
}