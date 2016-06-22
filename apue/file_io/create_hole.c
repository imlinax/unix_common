/*
 * 创建一个带有空洞的文件
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>
int main()
{
    char *pfilename = "file.hole";
    mode_t filemode = S_IRUSR;
    int fd = creat(pfilename,filemode);
    if(fd == -1)
    {
	perror("creat file error\n");
    }

    const char *pbuf1 = "hello";
    const char *pbuf2 = "world";

    int buf1size = strlen(pbuf1);
    int buf2size = strlen(pbuf2);
    if(write(fd,pbuf1,buf1size) != buf1size)
    {
	perror("write file error");
    }
    if(lseek(fd,10,SEEK_END) == -1)
    {
	perror("seek error");
    }
    if(write(fd,pbuf2,buf2size) != buf2size)
    {
	perror("write file error");
    }

    // close the file
    close(fd);
    return 0;
}
