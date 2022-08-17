/*===============================================
*   文件名称：puts.c
*   创 建 者：     
*   创建日期：2022年06月21日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int n = puts("hello world");
    int n1 = puts("welcome!");
    printf("%d %d\n", n, n1);
    return 0;
} 
