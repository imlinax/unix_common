#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
int main()
{
    int file = 0;
    char *pfilename = "newfile.txt";

    // 创建文件 
    file = creat(pfilename,S_IRUSR | S_IWUSR);
    printf("file = %d\n",file);
    // 关闭文件 
    int errcode = close(file);
    printf("errocode = %d\n",errcode);
    
    // 打开文件 
    char *pfile_readme = "README.md";
    file = open(pfile_readme,O_RDONLY);
    printf("file = %d\n",file);

    // 计算文件大小
    size_t size = 0;
    size = lseek(file,0,SEEK_END)-lseek(file,0,SEEK_SET);
    printf("file size = %d\n",size);
    
    // 测试是否能对标准输入设置偏移
    if(lseek(STDIN_FILENO,0,SEEK_CUR) == -1)
    {
	printf("can't seek stdin\n");
    }
    else
    {
	printf("seek stdin ok\n");
    }
    return 0;
}
