#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define LOCALFMT		100
void miniprintf(char *fmt, ...);

main()
{
	miniprintf("%o\n", 18);
}

void miniprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	char localfmt[LOCALFMT];
	int i, ival;
	unsigned uval;
	double dval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		i = 0;
		localfmt[i++] = '%';
		while (*(p + 1) && !isalpha(*(p + 1))) {
			localfmt[i++] = *++p;
		}
		localfmt[i++] = *(p + 1);
		localfmt[i] = '\0';
		switch (*++p) {
		case 'd':
		case 'i':
			ival = va_arg(ap, int);
			printf(localfmt, ival);
			break;
		case 'x':
		case 'X':
		case 'u':
		case 'o':
			uval = va_arg(ap, unsigned);
			printf(localfmt, uval);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf(localfmt, dval);
			break;
		case 's':
			sval = va_arg(ap, char *);
			for (sval = va_arg(ap, char *); *sval; sval++) {
				putchar(*sval);
			}
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}