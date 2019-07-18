#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define LOCALFMT	100

void miniscanf(char *fmt, ...);

main()
{
	int i;

	miniscanf("%d", &i);
	printf("%d\n", i);
}

void miniscanf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	char localfmt[LOCALFMT];
	int c, i, *ival;
	unsigned *uval;
	double *dval;

	i = 0;
	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			localfmt[i++] = *p;
			continue;
		}
		localfmt[i++] = '%';
		while (*(p + 1) && !isalpha(*(p + 1))) {
			localfmt[i++] = *++p;
		}
		localfmt[i++] = *(p + 1);
		localfmt[i] = '\0';
		switch (*++p)
		{
		case 'd':
		case 'i':
			ival = va_arg(ap, int *);
			scanf_s(localfmt, ival);
			break;
		case 'x':
		case 'X':
		case 'u':
		case '0':
			uval = va_arg(ap, unsigned *);
			scanf_s(localfmt, uval);
			break;
		case 'f':
			dval = va_arg(ap, double *);
			scanf_s(localfmt, dval);
			break;
		case 's':
			sval = va_arg(ap, char *);
			scanf_s(localfmt, sval);
			break;
		default:
			scanf_s(localfmt);
			break;
		}
		i = 0;
	}
	va_end(ap);
}
