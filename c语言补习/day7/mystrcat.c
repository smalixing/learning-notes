/*===============================================
*   文件名称：mystrcat.c
*   创 建 者：     
*   创建日期：2022年06月28日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char str[100], dst[100];
    printf("please input str string: ");
    gets(str);
    printf("please input dst string: ");
    gets(dst);
    char *ps = str, *pd = dst;
    while(*ps++);
    ps--;
    while(*ps++ = *pd++); //while(*ps);
    //while(*pd
    //{
    //  *ps++ = *pd++;
    //}
    //*ps = 0;

    puts(str);

    return 0;
} 
