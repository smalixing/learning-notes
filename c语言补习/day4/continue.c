/*===============================================
*   文件名称：break.c
*   创 建 者：     
*   创建日期：2022年06月23日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    for(int i = 1; i < 6; i++){
        for(int j = 1; j < 6; j++){
            if(j == 3)
                continue;
            printf("%d,%d ", i, j);
        }
        puts("");
    }
    return 0;
} 
