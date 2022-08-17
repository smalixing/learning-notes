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

    char buf[100] = {0};
    while(1){
        printf("Send: ");fflush(stdout);
        fgets(buf, 99, stdin);
        write(sfd, buf, 100);
        read(sfd, buf, 100);
        printf("Recv: %s", buf);
    }
    close(sfd);
    return 0;
} 
