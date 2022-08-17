/*===============================================
*   文件名称：broadcast.c
*   创 建 者：     
*   创建日期：2022年08月03日
*   描    述：
================================================*/
#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>

int main(int argc, char *argv[])
{ 
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(-1 == sfd){
        perror("socket");
        return -1;
    }

    //设置允许广播
    int broad = 1;
    if(-1 == setsockopt(sfd, SOL_SOCKET, SO_BROADCAST, &broad, sizeof(int))){
        perror("setsockopt");
        return -1;
    }
    

    //设置广播地址和端口
    struct sockaddr_in raddr;
    raddr.sin_family      = AF_INET;
    raddr.sin_port        = htons(8888);
    raddr.sin_addr.s_addr = inet_addr("192.168.10.255");
    char buf[32];
    while(1){
        printf("Send: ");
        fgets(buf, 32, stdin);
        if(-1 == sendto(sfd, buf, 32, 0, (void *)&raddr, sizeof(raddr))){
            perror("sendto");
            continue;
        }
    }

    return 0;
} 
