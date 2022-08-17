/*===============================================
*   文件名称：demo5.c
*   创 建 者：     
*   创建日期：2022年06月24日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char buf[30] = {0};
    int num = 0;
    printf("please input num: ");
    gets(buf);
    if(buf[0] == '-')
    {
        for(int i = 1; buf[i]; i++)
        {
            if(buf[i] < '0' || buf[i] > '9')
            {    
                break;
            }
            num = buf[i]-'0' + num*10;
        }
        num *= -1;
    }
    else
    {
        for(int i = 0; buf[i] != '\0'; i++)
        {
            if(buf[i] < '0' || buf[i] > '9')
                break;
            num = buf[i]-'0' + num*10;
        }
    }
    printf("%d\n", num);
    return 0;
} 
