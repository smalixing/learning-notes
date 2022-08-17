/*===============================================
*   文件名称：tcp_client.c
*   创 建 者：     
*   创建日期：2022年07月31日
*   描    述：
================================================*/
#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *send_msg(void *arg);
void *recv_msg(void *arg);

int main(int argc, char *argv[])
{ 
    if(3 > argc){
        printf("arc:%d argv[0]:%s IP PORT\n", argc, argv[0]);
        return -1;
    }
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == sfd){
        perror("socket");
        return -1;
    }

    //设置服务器的IP PORT
    struct sockaddr_in sddr = {0};
    sddr.sin_family      = AF_INET;
    sddr.sin_port        = htons(atoi(argv[2]));
    sddr.sin_addr.s_addr = inet_addr(argv[1]);

    //连接服务器
    if(-1 == connect(sfd, (void *)&sddr, sizeof sddr)){
        perror("connect");
        return -1;
    }
    
    pthread_t sid, rid;
    if(0 != pthread_create(&sid, NULL, send_msg, (void *)&sfd)){
        perror("pthread_create_send");
        exit(1);
    }

    if(0 != pthread_create(&rid, NULL, recv_msg, (void *)&sfd)){
        perror("pthread_create_recv");
        exit(1);
    }

    while(1){
        sleep(1);
    }
    close(sfd);
    return 0;
} 

void *send_msg(void *arg)
{
    int fd = *(int *)arg;
    char buf[32];
    while(1){
        fgets(buf, 32, stdin);
        write(fd, buf, 32);
        if(!strcmp(buf, "quit")){
            exit(0);
        }
    }
}

void *recv_msg(void *arg)
{
    int fd = *(int *)arg;
    char buf[32];
    int ret;
    while(1){
        ret = read(fd, buf, 32);
        if(0 > ret){
            perror("read");
            exit(1);
        }else if(0 == ret){
            exit(0);
        }
        if(!strcmp(buf, "quit")){
            exit(0);
        }
        printf("\nRecv: %s", buf);
    }

}
