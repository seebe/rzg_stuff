#include <sys/types.h>
#include <sys/stat.h>
#include <sys/signal.h>
#include <errno.h>

#undef errno
extern int errno;

void* __dso_handle;

void _exit(int code)
{
	while (1);
}

int _open(const char *name, int flags, int mode)
{
	return -1;
}

int _close(int __fildes)
{
	return -1;
}


int _fstat( int __fd, struct stat *__sbuf )
{
	__sbuf->st_mode = S_IFCHR; /* character special device */
	return 0;
}


pid_t _getpid(void)
{
	return 1;
}


int _isatty(int __fildes )
{
	return 1; /* IS a terminal */
}


int _kill(pid_t __pid, int __signal)
{
	errno = EINVAL;
	return -1;
}


_off_t _lseek(int __fildes, _off_t __offset, int __whence )
{
	return 0;
}


int _read(int __fd, void *__buf, size_t __nbyte)
{
	return 0;
}


caddr_t _sbrk(ptrdiff_t __incr)
{
	extern int __heap_start; /* Defined by the linker */
	static char* heap_end = NULL;
	caddr_t prev_heap_end;

	if (heap_end == NULL) {
		heap_end = (char*)&__heap_start;
	}
	prev_heap_end = (caddr_t)heap_end;
	heap_end += __incr;
	return prev_heap_end;
}


int _write(int __fd, const char *__buf, size_t __nbyte )
{
	return __nbyte;
}
