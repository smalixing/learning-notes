/*===============================================
*   文件名称：demo5.c
*   创 建 者：     
*   创建日期：2022年06月29日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int num;
    char str[100] = {0}, *ps = str;
    puts("input num: ");
    scanf("%d", &num);
    while(num){
        *ps++ = num % 10 + '0';
        num /= 10;
    }
    *ps-- = 0;
    char *q = str;
    while(q < ps){
        *q ^= *ps;
        *ps ^= *q;
        *q ^= *ps;
        q++, ps--;
    }
    puts(str);
    return 0;
} 
