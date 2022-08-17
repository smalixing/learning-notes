/*===============================================
*   文件名称：demo3.c
*   创 建 者：     
*   创建日期：2022年06月23日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int a, b, c;
    for(int i = 100; i < 1000; i++){
        a = i / 100;
        b = i / 10 % 10;
        c = i % 10;
        if(i == a*a*a + b*b*b + c*c*c){
            printf("%d ", i);
        }
    }
    puts("");

    int i = 100;
    while(i < 1000){
        a = i / 100;
        b = i / 10 % 10;
        c = i % 10;
        if(i == a*a*a + b*b*b + c*c*c){
            printf("%d ", i);
        }
        i++; 
    }
    puts("");
    return 0;
} 
