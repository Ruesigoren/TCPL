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
#include <fcntl.h>
#include <stdarg.h>

#ifdef UNIX
#define PERMS 0666
#else
#define PERMS 0x0180
#endif

void error(char *, ...);

int get(int fd, long pos, char *buf, int n)
{
    if (lseek(fd, pos, 0) >= 0) {
        return read(fd, buf, n);
    }
    else {
        return -1;
    }
}

int main(int argc, char *argv[])
{
    int n;
    char buf[BUFSIZ];
    int f1, f2;
    
    if (argc == 1) {
        error("Usage: get [filename]");
    }
    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1) {
        error("Can't open %s", argv[1]);
    }
    if ((f2 = creat(argv[2], PERMS)) == -1) {
        error("Can't creat %s, mode %03o", argv[2], PERMS);
    }
    if ((n = get(f1, BUFSIZ / 2, buf, BUFSIZ)) > 0) {
        if (write(f2, buf, n) != n) {
            error("cp: write error on file %s", argv[2]);
        }
    }
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