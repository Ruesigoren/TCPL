#include <stdio.h>

#define	MAX_WORD_LENGTH		15
#define MAX_HIST_LENGTH		11
#define IN_WORD				1
#define OUT_OF_WORD			0

main()
{
	int c, i, j, state, nc, wl[MAX_WORD_LENGTH];
	int overflow;
	int maxvalue;

	state = OUT_OF_WORD;
	nc = 0;
	overflow = 0;
	for (i = 0; i < MAX_WORD_LENGTH; ++i)
		wl[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN_WORD) {		//因为写错 state = IN_WORD 而导致不可预知的后果
				state = OUT_OF_WORD;
				if (nc > 0) {
					if (nc < MAX_WORD_LENGTH)
						++wl[nc];
					else
						++overflow;
				}
			}
		}
		else if (state == OUT_OF_WORD) {
			state = IN_WORD;
			nc = 1;
		}
		else
			++nc;
	}
	maxvalue = wl[0];
	for (i = 1; i < MAX_WORD_LENGTH; ++i) {
		if (maxvalue < wl[i])
			maxvalue = wl[i];
	}
	for (i = MAX_HIST_LENGTH; i > 0; --i) {
		for (j = 1; j < MAX_WORD_LENGTH; ++j)
			if (wl[j] * MAX_HIST_LENGTH / maxvalue >= i)
				printf("  *  ");
			else
				printf("     ");
		putchar('\n');
	}
	for (i = 1; i < MAX_WORD_LENGTH; ++i)
		printf("%4d", i);
	putchar('\n');
	for (i = 1; i < MAX_WORD_LENGTH; ++i)
		printf("%4d", wl[i]);
	putchar('\n');
	if (overflow > 0)
		printf("There are %d words >= %d\n", overflow, MAX_WORD_LENGTH);
}
