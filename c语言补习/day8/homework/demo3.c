/*===============================================
*   文件名称：demo1.c
*   创 建 者：     
*   创建日期：2022年06月29日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int op = 0;
    char str[100];
    printf("input str sting: ");
    gets(str);
    printf("input num: ");
    scanf("%d", &op);

    char *ps = str, ch, *pt;
    while(*ps++);
    ps -= 2;
    pt = ps;
    while(op--){
        ps = pt;
        ch = *ps;
        while(ps != str){
            *ps = *(ps-1);
            ps--;
        }
        *ps = ch;
    }
    puts(str);    

    return 0;
} 
