/*===============================================
*   文件名称：main.c
*   创 建 者：     
*   创建日期：2022年08月01日
*   描    述：
================================================*/
#include <stdio.h>
#include "ser.h"
#include <pthread.h>

//线程执行函数
void *server_thread_handle(void *arg);

int main(int argc, char *argv[])
{ 
    int fd = tcp_server_init("0.0.0.0", 6666, 10);
    while(1){
        pthread_t tid;
        
        int nfd = tcp_server_wait(fd);
        
        if(0 != pthread_create(&tid, NULL, server_thread_handle, &nfd)){
            close(nfd);
            continue;
        }
    }
    return 0;
} 

void *server_thread_handle(void *arg)
{
    int fd = *(int *)arg;
    char buf[SIZE];
    int ret = -1;
    while(1){
        ret = read(fd, buf, SIZE);
        if(ret <= 0){
            close(fd);
            break;
        }
        printf("Recv: %s", buf);
        write(fd, buf, SIZE);
    }
}
