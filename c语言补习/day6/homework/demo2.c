/*===============================================
*   文件名称：demo2.c
*   创 建 者：     
*   创建日期：2022年06月27日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char str[100], dst[100];
    printf("input str sting: ");
    gets(str);
    printf("input dst sting: ");
    gets(dst);

    int i = 0, j = 0;
    while(str[i++]);
    i--;
    /*
    while(dst[j])
    {
        str[i++] = dst[j++]; //str[i] = dst[j]; i++, j++;
    }
    str[i] = 0;
    */
    while(str[i++] = dst[j++]);

    puts(str);
    return 0;
} 
