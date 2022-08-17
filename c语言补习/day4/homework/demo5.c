/*===============================================
*   文件名称：demo5.c
*   创 建 者：     
*   创建日期：2022年06月23日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int N, i, j, z;
    printf("please input num: ");
    scanf("%d", &N);

    for(i = 1; i <= N; i++){
        for(z = 1; z <= N-i; z++)
            printf(" ");
        for(j = 1; j <= 2*i-1; j++)
            printf("*");
        puts("");
    } 

    return 0;
} 
