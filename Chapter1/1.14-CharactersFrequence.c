#include <stdio.h>
#include <ctype.h>

#define MAXHIST		15		/* max length of histogram */
#define MAXCAHR		128		/* max different characters */

/* print horizontal histogram frq. of  different characters */
main()
{
	int c, i;
	int len;				/* length of each bar */
	int maxvalue;			/* maximum value of cc[] */
	int cc[MAXCAHR];		/* character counters */

	for (i = 0; i < MAXCAHR; ++i)
		cc[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c < MAXCAHR)
			++cc[c];
	}
	maxvalue = 0;
	for (i = 0; i < MAXCAHR; ++i)
		if (maxvalue < cc[i])
			maxvalue = cc[i];
	for (i = 1; i < MAXCAHR; ++i) {
		if (isprint(i))
			printf("%5d - %c - %5d", i, i, cc[i]);
		else
			printf("%5d - %5d", i, cc[i]);
		if (cc[i] > 0) {
			if (len = cc[i] * MAXHIST / maxvalue <= 0)
				len = 1;
		}
		else
			len = 0;
		while (len > 0) {
			putchar(' * ');
			--len;
		}
		putchar('\n');
	}
}
