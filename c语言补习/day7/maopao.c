/*===============================================
*   文件名称：maopao.c
*   创 建 者：     
*   创建日期：2022年06月28日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int a[6] = {6,5,4,3,2,1}, *pa = a;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5-i; j++){
            if(*(pa+j) > *(pa+j+1)){
                *(pa+j) ^= *(pa+j+1);
                *(pa+j+1) ^= *(pa+j);
                *(pa+j) ^= *(pa+j+1);
            }
        }
    }

    for(int i = 0; i < 6; i++)
        printf("%d ", *pa++);
    puts("");

    return 0;
} 
