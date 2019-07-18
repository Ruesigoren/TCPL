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
	int cnt;
	char *ptr;
	char *base;
	int flag;
	int fd;
} FILEx;

enum _flags {
	_READ = 01,
	_WRITE = 02,
	_UNBUF = 04,
	_EOF = 010,
	_ERR = 020
};

FILEx _iob[OPEN_MAX];


int fseekx(FILEx *fp, long offset, int origin)
{
	unsigned nc;
	long rc = 0;

	if (fp->flag & _READ) {
		if (origin == -1) {
			offset -= fp->cnt;
		}
		rc = lseek(fp->fd, offset, origin);
		fp->cnt = 0;
	}
	else if (fp->flag & _WRITE) {
		if ((nc = fp->ptr - fp->base) > 0) {
			if (write(fp->fd, fp->base, nc) != nc) {
				rc = -1;
			}
		}
		if (rc != -1) {
			rc = lseek(fp->fd, offset, origin);
		}
	}
	return (rc == -1) ? -1 : 0;
}
