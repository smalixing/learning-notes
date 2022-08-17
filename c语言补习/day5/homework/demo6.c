/*===============================================
*   文件名称：demo6.c
*   创 建 者：     
*   创建日期：2022年06月24日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char buf[20] = {0};
    puts("input string: ");
    gets(buf);

    int i = 0, j;
    while(buf[i]) //while(buf[i]!='\0')
    {
        if(' ' == buf[i])
        {
            j = i;  //记录空格的下标
            //依次左移
            while(buf[j])
            {
                buf[j] = buf[j+1];
                j++;
            }
            i--;
        }
        i++;
    }
    puts(buf);

    return 0;
} 
