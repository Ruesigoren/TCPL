#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <sys/syscall.h>
#include <io.h>
#include <process.h>


#define	EOF			(-1)
#define OPEN_MAX	20

typedef struct {
	unsigned is_read : 1;
	unsigned is_write : 1;
	unsigned is_unbuf : 1;
	unsigned is_buf : 1;
	unsigned is_eof : 1;
	unsigned is_err : 1;
} flags;

typedef struct {
	int cnt;
	char *ptr;
	char *base;
	int flag;
	int fd;
} FILEx;

enum _flags {
	_READ	=	01,
	_WRITE	=	02,
	_UNBUF	=	04,
	_EOF	=	010,
	_ERR	=	020
};

FILEx _iob[OPEN_MAX];

int _flushbuf(int x, FILEx *fp)
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
	*fp->ptr++ = (char)x;
	fp->cnt = bufsize - 1;
	return x;
}

int fflushx(FILEx *fp)
{
	int rc = 0;

	if (fp < _iob || fp >= _iob + OPEN_MAX) {
		return EOF;
	}
	if (fp->flag & _WRITE) {
		rc = _flushbuf(0, fp);
	}
	fp->ptr = fp->base;
	fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	return rc;
}

int fclosex(FILEx *fp)
{
	int rc;

	if ((rc = fflushx(fp)) != EOF) {
		free(fp->base);
		fp->ptr = NULL;
		fp->cnt = 0;
		fp->base = NULL;
		fp->flag &= -(_READ | _WRITE);
	}
	return rc;
}


main()
{

}
