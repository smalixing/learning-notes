/*===============================================
*   文件名称：demo2.c
*   创 建 者：     
*   创建日期：2022年06月24日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    //x记录最大元素的下标
    int a[5] = {11, -7, 9, 3, 10}, max = a[1], x = 1;
    for(int i = 0; i < 5; i++)
    {
        if(max < a[i]){
            max = a[i];
            x = i;
        }
    }

    printf("max:%d  pos:%d\n", max, x);

    return 0;
} 
