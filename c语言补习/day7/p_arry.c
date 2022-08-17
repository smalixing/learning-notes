/*===============================================
*   文件名称：p_arry.c
*   创 建 者：     
*   创建日期：2022年06月28日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12}, *p = &a[0][0]; //*p = a[0];
    int max = *p;

    for(int i = 0; i < 3*4; i++){
        if(max < *p)
        {
            max = *p;
        }
        p++;
    }
    p = a[0];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%-3d", *p++);
        }
        puts("");
    }
    printf("max = %d\n", max);
    return 0;
} 
