/*===============================================
*   文件名称：demo6.c
*   创 建 者：     
*   创建日期：2022年06月23日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int j;
    for(int i = 2; i < 1001; i++){
        for(j = 2; j < i; j++){
            if(i % j == 0)
                break;
        }
        if(j == i){
            printf("%d ", i);
        }
    }
    puts("");
    return 0;
} 
