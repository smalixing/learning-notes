/*===============================================
*   文件名称：ser.h
*   创 建 者：     
*   创建日期：2022年08月01日
*   描    述：
================================================*/
#ifndef _SER_H_
#define _SER_H_
#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

int tcp_server_init(char *ip, int port, int backlog);
int tcp_server_wait(int fd);

#endif

