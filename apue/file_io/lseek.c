#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>

int main(void)
{
    int fd = open("lseek.file",O_APPEND | O_RDWR); 
    if(fd == -1)
    {
	perror("open file error");
	return -1;
    }
    // lseek read
    if(lseek(fd,2,SEEK_SET) == -1)
    {
	perror("lseek error");
	return -1;
    }

    char buf[20] = {0};
    ssize_t readlen = read(fd,buf,sizeof(buf));
    if(readlen == -1)
    {
	perror("read error");
	return -1;
    }
    buf[readlen] = '\0';
    printf("%s\n",buf);


    // lseek write
    if(lseek(fd,20,SEEK_END) == -1)
    {
	perror("lseek error");
	return -1;
    }

    char *pstr = "for test";
    ssize_t writelen = write(fd,pstr,strlen(pstr));
    if(writelen == -1)
    {
	perror("write error");
	return -1;
    }
    return 0;
}
