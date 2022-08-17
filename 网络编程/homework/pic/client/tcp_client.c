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
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

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
    char fname[20];
    printf("input get filename: ");
    fgets(fname, 20, stdin);
    int n = strlen(fname);
    //取消换行符
    fname[n-1] = 0;
    //发送文件名
    write(sfd, fname, 20);
    char stat[3];
    read(sfd, stat, 3);
    if(0 == strcmp(stat, "NO")){
        printf("服务器没有 %s 文件\n", fname);
        return 0;
    }
    int fd = open(fname, O_WRONLY|O_CREAT, 0777);
    if(-1 == fd){
        perror("open");
        return -1;
    }
    int len = -1;
    char buf[100];
    while(1){
        //接收图片数据的长度
        read(sfd, &len, 4);
        if(0 == len){
            puts("Recv OK");
            break;
        }
        //接收对应长度的图片数据
        read(sfd, buf, len);
        //将图片数据写入到文件
        write(fd, buf, len);
    }
    close(sfd);
    close(fd);
    return 0;
} 
