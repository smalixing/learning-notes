/*===============================================
*   文件名称：demo13.c
*   创 建 者：     
*   创建日期：2022年06月27日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char str[100];
    int num[5] = {0};
    puts("input string: ");
    gets(str);

    for(int i = 0; str[i]; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            num[0]++;
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            num[1]++;
        }
    }
    return 0;
} 
