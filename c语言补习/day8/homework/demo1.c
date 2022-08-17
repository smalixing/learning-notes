/*===============================================
*   文件名称：demo1.c
*   创 建 者：     
*   创建日期：2022年06月29日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int op = 0;
    char str[100], dst[100];
    printf("input str sting: ");
    gets(str);
    printf("input dst sting: ");
    gets(dst);
    
    char *ps = str, *pd = dst;

    while(*ps){
        if(*ps != *pd)
            break;
        ps++;
        pd++;
    }
    op = *ps - *pd;

    printf("op: %d\n", op);

    return 0;
} 
