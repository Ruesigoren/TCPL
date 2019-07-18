#include <stdio.h>

#define SNYM	10

union u_tag {
	int ival;
	float fval;
	char *sval;
} u;

enum { INT, FLOAT, STRING };

struct {
	char *name;
	int flags;
	int uflags;
	union {
		int ival;
		float fval;
		char *sval;
	} u;
} systab[SNYM];

main()
{
	int utype;

	u.sval = "hello";
	systab[0].u.sval = "world";
	while (1) {
		printf("utype: ?\n");
		scanf_s("%d", &utype);
		if (utype == INT) {
			//printf("%d\n", u.ival);
			printf("%d\n", systab[0].u.ival);
		}
		else if (utype == FLOAT) {
			//printf("%f\n", u.fval);
			printf("%f\n", systab[0].u.fval);
		}
		else if (utype == STRING) {
			//printf("%s\n", u.sval);
			printf("%s\n", systab[0].u.sval);
		}
		else {
			printf("bad type %d in utype\n", utype);
		}
	}
}

//#define KEYWORD		01
//#define EXTERNAL		02
//#define STATIC		04

enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04 };

struct {
	unsigned int is_keyword : 1;
	unsigned int is_extern : 1;
	unsigned int is_static : 1;
} flags;
