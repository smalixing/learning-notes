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
    struct ip_mreqn mreq;
    mreq.imr_multiaddr.s_addr = inet_addr("224.3.3.3");
    mreq.imr_address.s_addr   = inet_addr("0.0.0.0");
    mreq.imr_ifindex          = if_nametoindex("ens33");

    //创建多播组
    if(-1 == setsockopt(sfd, IPPROTO_IP, IP_MULTICAST_IF, &mreq, sizeof(mreq))){
        perror("setsockopt");
        return -1;
    }

    //设置接收组的IP PORT
    struct sockaddr_in raddr;
    raddr.sin_family         = AF_INET;
    raddr.sin_port           = htons(8888); 
    raddr.sin_addr.s_addr    = inet_addr("224.3.3.3"); //向多播组发送

    char buf[32];
    while(1){
        printf("input> ");
        fgets(buf, 32, stdin);
        if(-1 == sendto(sfd, buf, 32, 0, (void *)&raddr, sizeof(raddr))){
            perror("sendto");
            return -1;
        }
    }
        return 0;
} 
