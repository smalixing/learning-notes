/*===============================================
*   文件名称：mystrncpy.c
*   创 建 者：     
*   创建日期：2022年06月24日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char a[100], b[100];
    int n;
    printf("please input a string: ");
    gets(a);
    printf("please input b string: ");
    gets(b);
    printf("please input copy num: ");
    scanf("%d", &n);
    printf("a: %s\n", a);

    int i;
    for(i = 0; i < n; i++)
    {
        if(0 == b[i])
            break;
        a[i] = b[i];
    }
    a[i] = 0;
    printf("copy a: %s\n", a);

    return 0;
} 
