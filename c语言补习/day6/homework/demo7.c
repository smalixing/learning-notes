/*===============================================
*   文件名称：demo7.c
*   创 建 者：     
*   创建日期：2022年06月27日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int num, i;
    char str[100] = {0};
    printf("input num: ");
    scanf("%d", &num);
    for(i = 0; num;i++)
    {
        str[i] = num % 10 + '0';
        num /= 10;  // num = num / 10;
    }

    for(int j = 0; j < i/2; j++)
    {
        str[j] ^= str[i-j-1];
        str[i-j-1] ^= str[j];
        str[j] ^= str[i-j-1];
    }
    
    puts(str);


    return 0;
} 
