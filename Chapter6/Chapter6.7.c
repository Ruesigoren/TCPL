#include <stdio.h>
#include <stdlib.h>

#define MAXLINES			100

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

typedef int Length;

Length len, maxlen;
Length *lengths[10];

typedef char *String;

String p, lineptr[MAXLINES], alloc(int);

int u_strcmp(String, String);

typedef struct tnode *Treeptr;

typedef struct tnode {
	char *word;
	int count;
	Treeptr left;
	Treeptr right;
} Treenode;

Treeptr talloc(void)
{
	return (Treeptr)malloc(sizeof(Treenode));
}

typedef int (*PFI)(char *, char *);

PFI Strcmp, Numcmp;


int main()
{
	p = (String)malloc(100);
}

String alloc(int len)
{

}