/*===============================================
*   文件名称：demo1.c
*   创 建 者：     
*   创建日期：2022年06月27日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char str[100];
    printf("input string: ");
    gets(str);
    int n = 0;
    int i = 0;
    /*
    for(i; str[i]; i++)
    {
        n++;
    }
    */

    while(str[i])  //str[i] != '\0'
    {
        i++;
        n++;
    }

    printf("input string len: %d\n", n);
    return 0;
} 
