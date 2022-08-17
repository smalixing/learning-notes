/*===============================================
*   文件名称：fd_set.c
*   创 建 者：     
*   创建日期：2022年08月02日
*   描    述：
================================================*/
#include <stdio.h>
#include <sys/select.h>

int main(int argc, char *argv[])
{ 
    printf("fd_set size: %d\n", sizeof(fd_set));
    return 0;
} 
