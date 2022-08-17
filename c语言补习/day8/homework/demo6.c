/*===============================================
*   文件名称：demo6.c
*   创 建 者：     
*   创建日期：2022年06月29日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char str[100], *p = str, *q, *t;
    puts("input string: ");
    gets(str);

    while(*p){
        q = p+1;
        while(*q){
            if(*p == *q){
                t = q;
                while(*t){
                    *t = *(t+1);
                    t++;
                }
                q--;
            }
            q++;
        }
        p++;
    }

    puts(str);

    return 0;
} 
