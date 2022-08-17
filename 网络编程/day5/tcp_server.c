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

int main(int argc, char *argv[])
{ 
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == sfd){
        perror("socket");
        return -1;
    }

    struct sockaddr_in sddr, cddr;
    sddr.sin_family      = AF_INET;
    sddr.sin_port        = htons(8888);
    sddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(-1 == bind(sfd, (void *)&sddr, sizeof sddr)){
        perror("bind");
        return -1;
    }

    if(-1 == listen(sfd, 10)){
        perror("listen");
        return -1;
    }
    puts("listen...");

    socklen_t len = sizeof cddr;
    int nfd = accept(sfd, (void *)&cddr, &len);
    if(-1 == nfd){
        perror("accept");
        return -1;
    }

    printf("IP:%s PORT:%d connected!\n", inet_ntoa(cddr.sin_addr),ntohs(cddr.sin_port));
    
    char buf[100] = {0};
    while(1){
        int ret = read(nfd, buf, 100);
        if(ret < 0){
            perror("read");
            exit(-1);
        }
        printf("recv:\n%s", buf);
        fgets(buf, 99, stdin);
        write(nfd, buf, 100);
    }

    return 0;
} 
