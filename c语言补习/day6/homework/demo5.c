/*===============================================
*   文件名称：demo5.c
*   创 建 者：     
*   创建日期：2022年06月27日
*   描    述：
================================================*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{ 
    char str[100];
    puts("input string: ");
    gets(str);
    int m;
    puts("input move num:");
    scanf("%d", &m);
    int n = strlen(str);
    char ch;
    while(m--)
    {
        ch = str[n-1];
        for(int i = n-1; i > 0; i--)
            str[i] = str[i-1];
        str[0] = ch;
    }
    puts(str);
    return 0;
} 
