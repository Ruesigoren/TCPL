#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE			101

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

struct nlist *hashtab[HASHSIZE];

int hash(char *name);
struct nlist *install(char *name, char *defn);
struct nlist *lookup(char *name);
char *u_strdup(char *name);
void undef(char *name);

int main()
{
	struct nlist *np;
	
	install("Hello", "1");
	np = lookup("Hello");
	printf("%s\n", np->defn);
	undef("Hello");
	printf("%s\n", np->defn);
	getchar();
}

int hash(char *name)
{
	unsigned hashval;
	
	for (hashval = 0; *name != '\0'; name++) {
		hashval = *name + 31 *hashval;
	}
	return hashval % HASHSIZE;
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	int hashval;
	
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

struct nlist *lookup(char *name)
{
	struct nlist *np;
	
	for (np = hashtab[hash(name)]; np != NULL; np = np->next) {
		if (strcmp(np->name, name) == 0) {
			return np;
		}
	}
	return NULL;
}

void undef(char *name)
{
	struct nlist *prev, *np;
	int h;
	
	prev = NULL;	//指针变量需要初始化
	h = hash(name);
	for (np = hashtab[h]; np != NULL; np = np->next) {
		if (strcmp(np->name, name) == 0) {
			break;
		}
		prev = np;
	}
	if (np != NULL) {
		if (prev == NULL) {
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

char *u_strdup(char *name)
{
	char *p;

	p = (char *)malloc(strlen(name) + 1);
	if (p != NULL) {
		strcpy(p, name);
	}
	return p;
}