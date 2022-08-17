/*===============================================
*   文件名称：main.c
*   创 建 者：     
*   创建日期：2022年08月01日
*   描    述：
================================================*/
#include <stdio.h>
#include "ser.h"
#include <signal.h>
#include <sys/wait.h>

//子进程的处理函数
void server_child_handle(int fd);

//信号处理函数
void wait_child_handle(int no);

int main(int argc, char *argv[])
{ 
    int fd = tcp_server_init("0.0.0.0", 6666, 10);
    if(-1 == fd){
        return -1;
    }
    
    //将SIGCHILD信号和信号处理函数关联
    signal(SIGCHLD, wait_child_handle);
    while(1){
        int nfd = tcp_server_wait(fd);
        if(-1 == nfd){
            continue;
        }
        
        pid_t pid = fork();
        if(-1 == pid){   //err
            continue;
        }else if(0 == pid){ //子进程
            close(fd);  //关掉的是子进程的fd
            server_child_handle(nfd);
            break;
        }else{
            close(nfd); //关掉的是父进程的nfd,避免资源浪费
        }
    }
    
    return 0;
} 

void server_child_handle(int fd)
{
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

void wait_child_handle(int no)
{
    waitpid(-1, NULL, WNOHANG);
}
