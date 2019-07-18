#include <stdio.h>
#include <stdlib.h>
//#include <syscall.h>
#include <io.h>
#include <process.h>

typedef long			Align;

union header {
	struct {
		union header *ptr;
		unsigned size;
	} s;
	Align x;
};

typedef union header	Header;

unsigned bfree(char *p, unsigned n)
{
	Header *hp;

	if (n < sizeof(Header)) {
		return 0;
	}
	hp = (Header *)p;
	hp->s.size = n / sizeof(Header);
	free((void *)(hp + 1));
	return hp->s.size;
}
