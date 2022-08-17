/*===============================================
*   文件名称：strcpy.c
*   创 建 者：     
*   创建日期：2022年06月24日
*   描    述：
================================================*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{ 
    char a[100], b[100];
    puts("input a string: ");
    gets(a);
    puts("input b string: ");
    gets(b);
    printf("a string: %s\n", a);
    printf("b string: %s\n", b);

    strcpy(a, b);
    printf("a string: %s\n", a);
    printf("b string: %s\n", b);

    return 0;
} 
