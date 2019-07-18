#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE     100

void filecopy(FILE *ifp, FILE *ofp);
char *u_fgets(char *s, int n, FILE *iop);
int u_fputs(char *s, FILE *iop);
int u_getline(char *line, int max);

int main(int argc, char *argv[])
{
    FILE *fp;
    char *prog = argv[0];

    if (argc == 1) {
        filecopy(stdin, stdout);
    }
    else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            }
            else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
    }
    getchar();
    exit(0);
}

void filecopy(FILE *ifp, FILE *ofp)
{
    char *p;
    char buf[MAXLINE];

    while ((p = u_fgets(buf, MAXLINE, ifp)) != NULL) {
        u_fputs(buf, stdout);
    }
}

char *u_fgets(char *s, int n, FILE *iop)
{
    register int c;
    register char *cs;
    
    cs = s;
    while (--n > 0 && (c = getc(iop)) != EOF) {
        if ((*cs++ = c) == '\n') {
            break;
        }
    }
    *cs = '\0';
    return (c == EOF && cs == s) ? NULL : s;
}

int u_fputs(char *s, FILE *iop)
{
    int c;
    
    while (c = *s++) {
        putc(c, iop);
    }
    return ferror(iop) ? EOF : 1;
}

int u_getline(char *line, int max)
{
    if (u_fgets(line, max, stdin) == NULL) {
        return 0;
    }
    else {
        return strlen(line);
    }
}