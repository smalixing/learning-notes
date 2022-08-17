/*===============================================
*   文件名称：if2.c
*   创 建 者：     
*   创建日期：2022年06月22日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char ch;
    printf("please input char:\n");
    scanf("%c", &ch);
    if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z'){
        if(ch >= 'A' && ch <= 'Z'){
            ch += 32;
        }else{
            ch -= 32;
        } 
    }else{
        puts("input err");
    }
    printf("%c\n", ch);

    return 0;
} 
