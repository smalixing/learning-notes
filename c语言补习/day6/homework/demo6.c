/*===============================================
*   文件名称：demo6.c
*   创 建 者：     
*   创建日期：2022年06月27日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char str[100], ch;
    printf("input string: ");
    gets(str);
    printf("input delete char: ");
    scanf("%c", &ch);
    int i, j;

    for(i = 0; str[i]; i++)
    {
        if(ch == str[i])
        {
            j = i;
            while(str[j])
            {
                str[j] = str[j+1];
                j++;
            }
            i--;
        }
    }

    puts(str);
    return 0;
} 
