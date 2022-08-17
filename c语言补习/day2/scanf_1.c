/*===============================================
*   文件名称：scanf_1.c
*   创 建 者：     
*   创建日期：2022年06月21日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char a[20], b[20];
    scanf("%s%*c",a);
    //getchar();
    gets(b);
    puts("---------");
    puts(a);
    puts(b);
    return 0;
} 
