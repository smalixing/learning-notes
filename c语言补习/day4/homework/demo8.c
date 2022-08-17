/*===============================================
*   文件名称：demo8.c
*   创 建 者：     
*   创建日期：2022年06月23日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int i = 1, sum = 0;
loop:
    sum += i;
    i++;
    if(i <= 100)
        goto loop;
    printf("sum = %d\n", sum);
    return 0;
} 
