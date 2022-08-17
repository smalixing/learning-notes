/*===============================================
*   文件名称：demo2.c
*   创 建 者：     
*   创建日期：2022年06月27日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int n;
    puts("input num: ");
    scanf("%d", &n);
    int a[n][n];
    for(int i = 0; i < n; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
    }

    for(int i = 2; i < n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            a[i][j] = a[i-1][j] + a[i-1][j-1];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            printf("%-5d", a[i][j]);
        }
        puts("");
    }
    return 0;
} 
