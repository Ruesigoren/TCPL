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

#ifdef UNIX
#define PERMS 0666
#else
#define PERMS 0x0180
#endif

#undef NULL
#define NULL        0
#undef EOF
#define EOF         (-1)
#undef BUFSIZ
#define BUFSIZ      1024
#define OPEN_MAX    20

typedef struct MyFile {
    int cnt;
    char *ptr;
    char *base;
    int flag;
    int fd;
} uFILE;

//extern uFILE _iob[OPEN_MAX];
uFILE _iob[OPEN_MAX];

#undef stdin
#define stdin   (&_iob[0])
#undef stdout
#define stdout  (&_iob[1])
#undef stderr
#define stderr  (&_iob[2])

enum _flags {
    _READ   =   01,
    _WRITE  =   02,
    _UNBUF  =   04,
    _EOF    =   010,
    _ERR    =   020
};

uFILE _iob[OPEN_MAX] = {
    { 0, (char *)0, (char *)0, _READ, 0 },
    { 0, (char *)0, (char *)0, _WRITE, 1 },
    { 0, (char *)0, (char *)0, _READ | _UNBUF, 2 }
};

int _fillbuf(uFILE *);
int _flushbuf(int, uFILE *);

#define feof(p)     (((p)->flag & _EOF) != 0)
#define ferror(p)   (((p)->flag & _ERR) != 0)
#define fileno(p)   ((p)->fd)

#define getc(p)     (--(p)->cnt >= 0 \
                ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p)   (--(p)->cnt >= 0 \
                ? *(p)->ptr++ = (x) : _flushbuf((x), p))
#define getchar()   getc(stdin)
#define putchar(x)  putc((x), stdout)


//#define PERMS       0666

uFILE *u_fopen(char *name, char *mode);

int main()
{
    uFILE *fp = u_fopen("t.c", "r");

    if (fp != NULL) {
        char c;

        while ((c = getc(fp)) != EOF) {
            putchar(c);
        }
    }
    else {
        puts("Error");
    }
    putchar('\0');
    printf("%s", stdout->base);

    char c, d;
    uFILE *fp2 = u_fopen("fp2.c", "w");

    c = getc(stdin);
    putc(c, fp2);   //写到结构体fp2中
    _flushbuf(c, fp2);//写到文件fp2.c中
    return 0;
}

uFILE *u_fopen(char *name, char *mode)
{
    int fd;
    uFILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a') {
        return NULL;
    }
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++) {
        if ((fp->flag & (_READ | _WRITE)) == 0) {
            break;
        }
    }
    if (fp >= _iob + OPEN_MAX) {
        return NULL;
    }
    if (*mode == 'w') {
        fd = creat(name, PERMS);
    }
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1) {
            fd = creat(name, PERMS);
        }
        lseek(fd, 0L, 2);
    }
    else {
        fd = open(name, O_RDONLY, 0);
    }
    if (fd == -1) {
        return NULL;
    }
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}

int _fillbuf(uFILE *fp)
{
    int bufsize;

    if ((fp->flag & (_READ | _EOF | _ERR)) != _READ) {
        return EOF;
    }
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL) {
        if ((fp->base = (char *)malloc(bufsize)) == NULL) {
            return EOF;
        }
    }
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1) {
            fp->flag |= _EOF;
        }
        else {
            fp->flag |= _ERR;
        }
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char)*fp->ptr++;
}

int _flushbuf(int n, uFILE *fp)
{
    unsigned nc;
    int bufsize;

    if (fp < _iob || fp >= _iob + OPEN_MAX) {
        return EOF;
    }
    if ((fp->flag & (_WRITE | _ERR)) != _WRITE) {
        return EOF;
    }
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL) {
        if ((fp->base = (char *)malloc(bufsize)) == NULL) {
            fp->flag |= _ERR;
            return EOF;
        }
    }
    else {
        nc = fp->ptr - fp->base;
        if (write(fp->fd, fp->base, nc) != nc) {
            fp->flag |= _ERR;
            return EOF;
        }
    }
    fp->ptr = fp->base;
    *fp->ptr++ = (char)n;
    fp->cnt = bufsize - 1;
    return n;
}