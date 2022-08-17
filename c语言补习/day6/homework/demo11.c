/*===============================================
*   文件名称：demo11.c
*   创 建 者：     
*   创建日期：2022年06月27日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char str[100], ch;
    puts("input string:");
    gets(str);
    
    int i = 0, j, k;
    while(str[i])
    {
        ch = str[i];
        j = i+1;
        while(str[j])
        {
            if(ch == str[j])
            {
                k = j;
                while(str[k])
                {
                    str[k] = str[k+1];
                    k++;
                }
                j--;
            }
            j++;
        }
        i++;
    }
    puts(str);


    return 0;
} 
