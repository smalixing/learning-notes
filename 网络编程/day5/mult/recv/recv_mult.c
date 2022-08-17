/*===============================================
*   文件名称：send_mult.c
*   创 建 者：     
*   创建日期：2022年08月03日
*   描    述：
================================================*/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
 
#include <net/if.h>

int main(int argc, char *argv[])
{ 
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(-1 == sfd){
        perror("socket");
        return -1;
    }

    //设置多播组的IP
    struct ip_mreqn mreqn;
    mreqn.imr_multiaddr.s_addr = inet_addr("224.2.3.4");
    mreqn.imr_address.s_addr   = inet_addr("0.0.0.0");

    //加入多播组
    if(-1 == setsockopt(sfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreqn, sizeof(mreqn))){
        perror("setsockopt");
        return -1;
    }

    //设置接收组的IP PORT
    struct sockaddr_in raddr, saddr;
    raddr.sin_family         = AF_INET;
    raddr.sin_port           = htons(8888); 
    raddr.sin_addr.s_addr    = inet_addr("224.2.3.4"); //向多播组发送

    socklen_t len = sizeof(saddr);

    if(-1 == bind(sfd, (void *)&raddr, sizeof(raddr))){
        perror("bind");
        return -1;
    }

    char buf[32];
    while(1){
        if(-1 == recvfrom(sfd, buf, 32, 0, (void *)&saddr, &len)){
            perror("sendto");
            return -1;
        }
        printf("由IP->%s:%d send data:%s", inet_ntoa(saddr.sin_addr), ntohs(saddr.sin_port), buf);
    }
        return 0;
} 
