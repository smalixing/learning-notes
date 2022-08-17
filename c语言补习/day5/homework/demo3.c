/*===============================================
*   文件名称：demo3.c
*   创 建 者：     
*   创建日期：2022年06月24日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char buf[20] = {0};
    puts("input string:");
    gets(buf);

    for(int i = 0; buf[i] != '\0'; i++)
    {
        if('A' <= buf[i] && buf[i] <= 'Z'){
            buf[i] += 32;
        }
        else if('a' <= buf[i] && buf[i] <= 'z'){
            buf[i] -= 32;
        }
    }
    puts(buf);

    return 0;
} 
