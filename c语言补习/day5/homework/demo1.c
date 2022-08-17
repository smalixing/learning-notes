/*===============================================
*   文件名称：demo1.c
*   创 建 者：     
*   创建日期：2022年06月24日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int n;
    printf("please input num: ");
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)
    {
        printf("please input arr[%d]: ", i);
        scanf("%d", &a[i]);
    }

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    printf("%d\n", sum);
    return 0;
} 
