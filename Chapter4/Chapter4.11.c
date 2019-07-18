#define DEFAULT		0
#define	SYSV		1
#define BSD			2
#define MSDOS		3

#if (!defined SYSTEM) && (DEFAULT == 0)

#define SYSTEM DEFAULT

#endif

#define forever				for (; ;)
#define max(A, B)			((A) > (B) ? (A) : (B))
#define dprint(expr)		printf(#expr " = %g\n", expr);
#define paste(front, back)	front##back

#if SYSTEM == SYSV
	#define HDR	"sysv.h"
#elif SYSTEM == BSD
	#define HDR "bsd.h"
#elif SYSTEM == MSDOS
	#define HDR	"msdos.h"
#else
	#define HDR	<stdio.h>
#endif

#include HDR

#undef getchar

int getchar(void);

int main()
{
	int a = 2;
	double b = 3.1415926;
	char helloworld[] = "hi, hello world!";
	
#if defined SYSTEM
	a = 1;
#endif
	printf("%d\n", a);
	getchar();
	dprint(b);
	printf("%s", paste(hello, world));
	forever;
}

int getchar(void)
{
	printf("%d\n", SYSTEM);
}