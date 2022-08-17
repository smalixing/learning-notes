/*===============================================
*   文件名称：demo1.c
*   创 建 者：     
*   创建日期：2022年06月29日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char str[100], ch;
    printf("input str sting: ");
    gets(str);
    printf("input delete char: ");
    scanf("%c", &ch);

    char *ps = str, *q;
    while(*ps){
        if(ch == *ps){
            q = ps;
            while(*q){
                *q = *(q+1);
                q++;
            }
            ps--;
        }
        ps++;
    }

    puts(str);    

    return 0;
} 
