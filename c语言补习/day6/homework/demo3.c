/*===============================================
*   文件名称：demo3.c
*   创 建 者：     
*   创建日期：2022年06月27日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char str[100],dst[100];
    printf("input str string: ");
    gets(str);
    printf("input dst string: ");
    gets(dst);
    int cmp = 0, i;
    for(i = 0; str[i]; i++)
    {
        /*
        if(0 == str[i]-dst[i])
            continue;
        else
            break;
        */
        if(0 != str[i] - dst[i]) //str[i] != dst[i]
            break;
    }
    cmp = str[i] - dst[i];
    printf("cmp: %d\n", cmp);
    return 0;
} 
