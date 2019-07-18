//#define UNIX
#define WINDOWS

#ifdef UNIX
#include "syscalls.h"
#elif defined WINDOWS
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#include <process.h>
#endif

#include <stdio.h>

//#define VERSION_1
#define VERSION_2

int u_getchar(void);

int main()
{
    char buf[BUFSIZ];
    int n;
    
    while ((n = read(0, buf, BUFSIZ)) > 0) {
        write(1, buf, n);
    }

    int c;
    while ((c = u_getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}

/* version 1 */
#ifdef VERSION_1
int u_getchar(void)
{
    char c;
    
    return (read(0, &c, 1) == 1) ? (unsigned char)c : EOF;
}

/* version 2 */
#elif defined VERSION_2
int u_getchar(void)
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;
    
    if (n == 0) {
        n = read(0, buf, sizeof(buf));
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char )*bufp++ : EOF;
}

#endif