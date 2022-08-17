/*===============================================
*   文件名称：ser.c
*   创 建 者：     
*   创建日期：2022年08月01日
*   描    述：
================================================*/
#include "ser.h"

int tcp_server_init(char *ip, int port, int backlog)
{
	int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == sfd){
        perror("socket");
        return -1;
    }
    
    struct sockaddr_in sddr;
    
    sddr.sin_family      = AF_INET; 
    sddr.sin_port        = htons(port);
    sddr.sin_addr.s_addr = inet_addr(ip);
    
    if(-1 == bind(sfd, (void *)&sddr, sizeof sddr)){
        perror("bind");
        return -1;
    }

    if(-1 == listen(sfd, backlog)){
        perror("listen");
        return -1;
    }
    puts("Server-------OK");
    return sfd;
}

int tcp_server_wait(int fd)
{
	struct sockaddr_in cddr;
	socklen_t size = sizeof cddr;
    int nfd = accept(fd, (void *)&cddr, &size);
    if(-1 == nfd){
        perror("accept");
        return -1;
    }
    printf("IP:%s PORT:%d connected!\n", inet_ntoa(cddr.sin_addr),ntohs(cddr.sin_port));
    return nfd;
}

