/*===============================================
*   文件名称：demo1.c
*   创 建 者：     
*   创建日期：2022年06月23日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int n;
    printf("input num: ");
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        printf("please input a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    puts("");

    for(int i = 0; i < n/2; i++){
        a[i] ^= a[n-i-1];
        a[n-i-1] ^= a[i];
        a[i] ^= a[n-i-1];
    }

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    puts("");
    return 0;
} 
