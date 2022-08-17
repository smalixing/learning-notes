/*===============================================
*   文件名称：swap.c
*   创 建 者：     
*   创建日期：2022年06月29日
*   描    述：
================================================*/
#include <stdio.h>
void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main(int argc, char *argv[])
{ 
    int a = 10, b = 20;
    printf("a = %d b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d b = %d\n", a, b);

    return 0;
} 
