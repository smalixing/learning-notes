/*===============================================
*   文件名称：udp_send.c
*   创 建 者：     
*   创建日期：2022年08月02日
*   描    述：
================================================*/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <stdlib.h>


#define SIZE 32

int main(int argc, char *argv[])
{ 
    if(3 != argc){
        printf("Usage: %s <IP> <PORT>\n", argv[0]);
        return -1;
    }

    //socket建立套接字
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(-1 == sfd){
        perror("socket");
        return -1;
    }

    //设置接收方的IP PORT
    struct sockaddr_in r_addr, s_addr;
    r_addr.sin_family      = AF_INET;
    r_addr.sin_port        = htons(atoi(argv[2]));
    r_addr.sin_addr.s_addr = inet_addr(argv[1]);

    socklen_t len = sizeof(s_addr);

    char buf[SIZE];
    while(1){
        printf("Send: ");
        fgets(buf, SIZE, stdin);
        //发送数据
        if(0 > sendto(sfd, buf, SIZE, 0, (void *)&r_addr, sizeof(r_addr))){
            perror("sendto");
            continue;  //UDP是无连接，所以不需要结束程序
        }
        if(!strcmp(buf, "quit\n")){
            puts("game over");
            break;
        }
        
        //接收数据
        if(0 > recvfrom(sfd, buf, SIZE, 0, (void *)&s_addr, &len)){
            perror("recvfrom");
            continue;
        }
        printf("收到IP:%sPORT:%d Data:%s", inet_ntoa(s_addr.sin_addr), ntohs(s_addr.sin_port), buf);
    }
    return 0;
} 
