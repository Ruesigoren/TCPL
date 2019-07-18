#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <sys/syscall.h>
#include <io.h>
#include <process.h>


//#define NULL		0
#define	EOF			(-1)
//#define	BUFSIZ		1024
#define OPEN_MAX	20

typedef struct _flags {
	int _READ;
	int _WRITE;
	int _UNBUF;
	int _EOF;
	int _ERR;
} flags;

typedef struct {
	int cnt;
	char *ptr;
	char *base;
	struct _flags flags;
	int fd;
} FILEx;

FILEx _iob[OPEN_MAX];
//#define stdin	(&_iob[0])
//#define stdout	(&_iob[1])
//#define stderr	(&_iob[2])

//enum _flags {
//	_READ	=	01,
//	_WRITE	=	02,
//	_UNBUF	=	04,
//	_EOF	=	010,
//	_ERR	=	020
//};

int _fillbuffx(FILEx *);
//int _flushbuf(int, FILEx *);

//#define feof(p)		(((p)->flag * _EOF) != 0)
//#define ferror(p)	(((p)->flag * _ERR) != 0)
//#define fileno(p)	((p)->fd)
//
#define getcx(p)		(--(p)->cnt >= 0 \
				? (unsigned char) *(p)->ptr++ : _fillbuffx(p))
//#define putcx(x,p)	(--(p)->cnt >= 0 \
//				? *(p)->ptr++ = (x) : _flushbuf((x), p))
//#define getcharx()	getcx(stdin)
//#define putcharx(x)	putcx((x), stdout)


#define PERMS		0666

int is_empty(struct _flags flags)
{
	if (!flags._READ && !flags._WRITE && !flags._UNBUF &&
		!flags._EOF && !flags._ERR) {
		return 1;
	}
	return 0;
}

FILEx *fopenx(char *name, char *mode) {
	int fd;
	FILEx *fp;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a') {
		return NULL;
	}
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++) {
		//if (fp->flag.is_read == 0 && fp->flag.is_write == 0) {
		//	break;
		//}
		if (is_empty(fp->flags)) {
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
	if (*mode == 'r') {
		fp->flags._READ = 1;
		fp->flags._WRITE = 0;
	}
	else {
		fp->flags._READ = 0;
		fp->flags._WRITE = 1;
	}
	fp->base = NULL;
	fp->flags._UNBUF = 0;
	fp->flags._EOF = 0;
	fp->flags._ERR = 0;
	return fp;
}

int _fillbuffx(FILEx *fp)
{
	int bufsize;

	if(fp->flags._READ == 0) {
		return EOF;
	}
	bufsize = (fp->flags._UNBUF != 0) ? 1 : BUFSIZ;
	if (fp->base == NULL) {
		if ((fp->base = (char *)malloc(bufsize)) == NULL) {
			return EOF;
		}
	}
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0) {
		if (fp->cnt == -1) {
			fp->flags._EOF = 1;
		}
		else {
			fp->flags._ERR = 1;
		}
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char)*fp->ptr++;
}

int main(void)
{
	FILEx *fp = fopenx("t.c", "r");

	if (fp != NULL) {
		char c;

		while ((c = getcx(fp)) != EOF) {
			putchar(c);
		}
	}
	else {
		puts("Error");
	}
	return 0;
}
