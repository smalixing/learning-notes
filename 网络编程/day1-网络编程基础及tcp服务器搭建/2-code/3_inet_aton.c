#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc,const char *argv[])
{
    struct in_addr addr; //保存转化后的无符号二进制整数
    memset(&addr, 0, sizeof(addr));

    int ret  = inet_aton("127.0.0.1",&addr);//将点分形式IP转化成二进制无符号整数
    if(-1 == addr.s_addr)
    {
        printf("inet_aton error\n");
        return -1;
    }

    printf("addr.s_addr=%d\n",addr.s_addr);

    char* ip = inet_ntoa(addr); //将无符号二进制网络字节序转化点分形式
    printf("ip:%s\n",ip);
    return 0;
}
