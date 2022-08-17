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
    printf("input num: ");
    scanf("%d", &op);

    char *ps = str, *pd = dst;
    while(*ps++);
    ps--;

    while(op--){
        *ps++ = *pd++;
    }

    *ps = 0;
    puts(str);    

    return 0;
} 
