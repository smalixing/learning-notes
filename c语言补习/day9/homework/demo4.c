/*===============================================
*   文件名称：demo4.c
*   创 建 者：     
*   创建日期：2022年06月30日
*   描    述：
================================================*/
#include <stdio.h>
int myatoi(char *str)
{
    int op = 1, num = 0;
    if('-' == *str){
        op = -1;
        str++;
    }
    while(*str){
        if(*str < '0' || *str > '9')
            break;
        num = (*str - '0') + num*10;
        str++;
    }
    return num*op;
}

int main(int argc, char *argv[])
{ 
    char str[100];
    while(1){
        printf("input string: ");
        gets(str);
        printf("myatoi: %d\n", myatoi(str));
    }

    return 0;
} 
