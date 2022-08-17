/*===============================================
*   文件名称：mystrcpy.c
*   创 建 者：     
*   创建日期：2022年06月30日
*   描    述：
================================================*/
#include <stdio.h>
char *mystrcpy(char *str, char *dst)
{
    char *phead = str;
    while(*str++ = *dst++);
    return phead;
}

int main(int argc, char *argv[])
{ 
    char str[100], dst[100];
    gets(str);
    gets(dst);
    //puts(mystrcpy(str, dst));
    char *p = mystrcpy(str, dst);
    printf("str: %p p:%p\n", str, p);
    puts(p);
    printf("%ld\n", sizeof(mystrcpy));
    return 0;
} 
