/*===============================================
*   文件名称：demo1.c
*   创 建 者：     
*   创建日期：2022年06月30日
*   描    述：
================================================*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{ 
    char a[] = "abcdefgi", b[] = "ABC", c[] = "hello", d[] = "welcome";
    char *arr[4] = {a, b, c, d}, *pt;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3-i; j++)
        {
            if(strlen(arr[j]) > strlen(arr[j+1]))
            {
                pt = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = pt;
            }
        }
    }

    for(int i = 0; i < 4; i++)
        puts(arr[i]);

    return 0;
} 
