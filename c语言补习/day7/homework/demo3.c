/*===============================================
*   文件名称：demo3.c
*   创 建 者：     
*   创建日期：2022年06月28日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char str[3][10] = {0};
    for(int i = 0; i < 3; i++)
    {
        printf("input %d string: ", i);
        gets(str[i]);
    }
    char ch;
    printf("input delete char: ");
    scanf("%c", &ch);
    int k;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; str[i][j]; j++)
        {
            if(str[i][j] == ch)
            {
                k = j;
                while(str[i][k])
                {
                    str[i][k] =str[i][k+1];
                    k++;
                }
                j--;
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        puts(str[i]);
    }

    return 0;
} 
