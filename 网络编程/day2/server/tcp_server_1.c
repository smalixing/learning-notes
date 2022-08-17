/*===============================================
*   文件名称：tcp_server.c
*   创 建 者：     
*   创建日期：2022年07月31日
*   描    述：
================================================*/
#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//发送消息的线程执行函数
void *send_msg(void *arg);
void *recv_msg(void *arg);

int main(int argc, char *argv[])
{ 
    //应用层到底层的通道
    /*************************
     *AF_INET:     IPv4协议簇
     *SOCK_STREAM: TCP连接
     *0：          默认为0
     *retrun:      新的文件描述符
     *************************/
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == sfd){
        perror("socket");
        return -1;
    }

    //设置IP PORT
    struct sockaddr_in sddr, cddr;
    //使用memset清空sddr
    memset(&sddr, 0, sizeof sddr);
    //bzero清空cddr
    bzero(&cddr, sizeof cddr);
    //填充结构体的内容
    sddr.sin_family      = AF_INET;
    //htons将本机字节序转成网络字节序
    sddr.sin_port        = htons(8888);
    //将点分十进制的IP转成网络字节序
    //"0.0.0.0" == INADDR_ANY :任意IP(自己主机网卡的IP)
    sddr.sin_addr.s_addr = htonl(INADDR_ANY);

    /****************************************
     *bind:          将IP PORT和socket套接字绑定
     *sfd:           目标套接字的文件描述符
     *(void *)&sddr: 设置好的IP PORT
     * sizeof sddr : 设置的IP PORT的大小
     * return:       0或-1,表示成功或者失败
     ****************************************/
    if(-1 == bind(sfd, (void *)&sddr, sizeof sddr)){
        perror("bind");
        return -1;
    }

    /*************************************
     *listen: 监听套节字有无连接进来
     *sfd:    目标套接字的文件描述符
     *10：    监听队列的长度
     *return: 0或-1,表示是否成功
     *************************************/
    if(-1 == listen(sfd, 10)){
        perror("listen");
        return -1;
    }
    puts("listen...");

    /****************************************
     *accept: 和客户端建立新的连接
     *sfd:    要建立连接的套接字
     *cddr：  存储连接进来客户端的信息(IP PORT)
     *len:    上一个参数的大小
     *return: 表示新的连接
     *****************************************/
    socklen_t len = sizeof cddr;
    int nfd = accept(sfd, (void *)&cddr, &len);
    if(-1 == nfd){
        perror("accept");
        return -1;
    }

    //解析连接客户端的IP PORT
    //ntohs:     将网络字节序转换为本机字节序
    //inet_ntoa: 将网络字节序转换成点分十进制
    printf("IP:%s PORT:%d connected!\n", inet_ntoa(cddr.sin_addr),ntohs(cddr.sin_port));
    
    //创建两个子线程分别负责收和发消息
    pthread_t sid, rid;
    //创建发送消息的线程
    if(0 != pthread_create(&sid, NULL, send_msg, &nfd)){
        perror("pthread_create1");
        return -1;
    }

    //创建接收消息的线程
    if(0 != pthread_create(&rid, NULL, recv_msg, &nfd)){
        perror("pthread_create1");
        return -1;
    }

    while(1){
        sleep(1);
    }

    return 0;
} 

void *send_msg(void *arg)
{
    int fd = *(int *)arg;
    char buf[32] = {0};
    while(1){
        fgets(buf, 31, stdin);
        write(fd, buf, 32);
        if(0 == strcmp(buf, "quit")){
            exit(0);
        }
    }
}

void *recv_msg(void *arg)
{
    int fd = *(int *)arg;
    char buf[32] = {0};
    while(1){
        read(fd, buf, 32);
        if(0 == strcmp(buf, "quit")){
            exit(0);
        }
        printf("Recv: %s", buf);
    }
}
