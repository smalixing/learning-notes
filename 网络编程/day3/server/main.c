/*===============================================
*   文件名称：main.c
*   创 建 者：     
*   创建日期：2022年08月01日
*   描    述：
================================================*/
#include <stdio.h>
#include "ser.h"

int main(int argc, char *argv[])
{ 
    int fd = tcp_server_init("0.0.0.0", 6666, 10);
    int nfd = tcp_server_wait(fd);
    return 0;
} 
