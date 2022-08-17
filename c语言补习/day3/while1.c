/*===============================================
*   文件名称：while1.c
*   创 建 者：     
*   创建日期：2022年06月22日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int i = 4;
    while(i--){
        printf("%d ", i);
    }
    puts("");

    int j = 4;
    do{
        printf("%d ", j);
    }while(j--);
    puts("");

    return 0;
} 
