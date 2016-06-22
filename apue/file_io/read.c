#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>

int main(void)
{
    char *pfilename = "README.md";
    int fd = open(pfilename,O_RDONLY);
    if(fd == -1)
    {
	perror("open file error");
	return -1;
    }
    int newfd = dup(fd);
    char buf[20];
    memset(buf,0,sizeof(buf));
    ssize_t readlen = read(newfd,buf,sizeof(buf));
    if(readlen == -1)
    {
	perror("read file error");	
	return;
    }
    buf[sizeof(buf)-1] = '\0';
    printf("%s",buf);

    // close the file
    close(newfd);
    close(fd);
    return 0;
}
