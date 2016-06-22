#include <fcntl.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
    int val; 
    if(argc != 2)
    {
	fprintf(stderr,"usage:%s <file descriptor>",argv[0]);
	return;
    }

    val = fcntl(atoi(argv[1]),F_GETFL,0);
    if(val == -1)
    {
	fprintf(stderr,"fcntl error for fd %d",atoi(argv[1]));
	return;
    }
    // print access mode
    switch(val & O_ACCMODE)
    {
    case O_RDONLY:
	printf("read only ");
	break;
    case O_WRONLY:
	printf("write only ");
	break;
    case O_RDWR:
	printf("read write ");
	break;
    default:
	fprintf(stderr,"unkown access mode");
    }

    if(val & O_APPEND)
    {
	printf("append ");
    }
    if(val & O_NONBLOCK)
    {
	printf("nonblocking ");
    }

#if defined(O_SYNC)
    if(val & O_SYNC)
    {
	printf("sync ");
    }
#endif

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
    if(val & O_FSYNC)
    {
	printf("synchronus writes");
    }
#endif
    printf("\n");
    return 0;
}
