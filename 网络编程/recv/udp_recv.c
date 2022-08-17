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
    //socket建立套接字
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(-1 == sfd){
        perror("socket");
        return -1;
    }

    //设置接收方的IP PORT
    struct sockaddr_in r_addr, s_addr = {0};
    r_addr.sin_family      = AF_INET;
    r_addr.sin_port        = htons(7777);
    r_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    

    //绑定自己的IP PORT
    if(-1 == bind(sfd, (void *)&r_addr, sizeof(r_addr))){
        perror("bind");
        return -1;
    }
    puts("Udp_server-------OK");

    socklen_t len = sizeof(s_addr);

    char buf[SIZE];
    while(1){
        //接收数据
        if(0 > recvfrom(sfd, buf, SIZE, 0, (void *)&s_addr, &len)){
            perror("recvfrom");
            continue;
        }
        if(!strcmp(buf, "quit\n")){
            printf("注意IP:%sPORT:%d退出\n", inet_ntoa(s_addr.sin_addr), ntohs(s_addr.sin_port));
            continue;
        }
        printf("收到IP:%sPORT:%d Data:%s", inet_ntoa(s_addr.sin_addr), ntohs(s_addr.sin_port), buf);
        //发送数据
        if(0 > sendto(sfd, buf, SIZE, 0, (void *)&s_addr, sizeof(s_addr))){
            perror("sendto");
            continue;  //UDP是无连接，所以不需要结束程序
        }
        
        //接收数据
    }
    return 0;
} 
