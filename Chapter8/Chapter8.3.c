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
#include <stdlib.h>
#include <fcntl.h>
#include <stdarg.h>

#ifdef UNIX
#define PERMS 0666
#else
#define PERMS 0x0180
#endif

void error(char *, ...);

int main(int argc, char *argv[])
{
    int f1, f2, n;
    char buf[BUFSIZ];
    
    if (argc != 3) {
        error("Usage: cp from to");
    }
    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1) {
        error("cp: can't open %s", argv[1]);
    }
    if ((f2 = creat(argv[2], PERMS)) == -1) {
        error("cp: can't creat %s, mode %03o", argv[2], PERMS);
    }
    while ((n = read(f1, buf, BUFSIZ)) > 0) {
        if (write(f2, buf, n) != n) {
            error("cp: write error on file %s", argv[2]);
        }
    }
    return 0;
}

void error(char *fmt, ...)
{
    va_list args;
    
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}