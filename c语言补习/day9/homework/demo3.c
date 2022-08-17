/*===============================================
*   文件名称：demo3.c
*   创 建 者：     
*   创建日期：2022年06月30日
*   描    述：
================================================*/
#include <stdio.h>

int mystrcmp(char *str, char *dst)
{
    while(*str == *dst)
    {
        if(!*str)
            return 0;
        str++;
        dst++;
    }
    return *str - *dst;
}

int main(int argc, char *argv[])
{ 
    char str[100], dst[100];
    printf("input str string: ");
    gets(str);
    printf("input dst string: ");
    gets(dst);

    printf("cmp: %d\n", mystrcmp(str, dst));
    return 0;
} 
