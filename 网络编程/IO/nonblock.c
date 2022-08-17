/*===============================================
*   文件名称：nonblock.c
*   创 建 者：     
*   创建日期：2022年08月02日
*   描    述：
================================================*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <errno.h>

int main(int argc, char *argv[])
{ 
    char buf[100] = {0};
    read(0, buf, 100);
    printf("buf : %s\n", buf);
    
    //设置为非阻塞模式
    //先获取文件的状态
    int flag = fcntl(0, F_GETFL);
    //设置新的属性
    flag |= O_NONBLOCK;
    fcntl(0, F_SETFL, flag);

    while(1){
        bzero(buf, 100);
        if(-1 == read(0, buf, 100)){
            printf("errno: %d\n", errno);
            perror("read");
        }else{
            printf("buf : %s\n", buf);
        }
        sleep(1);
    }

    return 0;
} 
