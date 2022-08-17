/*===============================================
*   文件名称：scanf.c
*   创 建 者：     
*   创建日期：2022年06月21日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char ch;
    char str[100];
    int a;
    scanf("%c%s%d", &ch, str, &a);
    printf("%c\n%s\n%d\n", ch, str, a);
    return 0;
} 
