#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>
#include <string.h>

#include <unistd.h>

int main(void)
{
    char *pfilename = "write.file";
    mode_t mode = S_IRUSR | S_IWUSR;
    int fd = open(pfilename,O_RDWR | O_CREAT,mode);
    //int fd = open(pfilename,O_RDWR | O_CREAT ,mode);
    if(fd == -1)
    {
	perror("open file error");
	return -1;
    }
    char buf[20] = "hello\n";
    for(int i = 0; i < 20; i++)
    {
	ssize_t writelen = write(fd,buf,strlen(buf));
	if(writelen == -1)
	{
	    perror("write error");	
	    return -1;
	}
    }

    // sync data to disk
    //fsync(fd);
    // close the file
    close(fd);
    return 0;
}
