/*===============================================
*   文件名称：demo1.c
*   创 建 者：     
*   创建日期：2022年06月29日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int a[2][3] = {1,2,3,4,5,6};
    int *arr[2] = {a[0], a[1]};
    int sum = 0;

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
            sum += *(arr[i]+j);
    }
    printf("%d\n", sum);

    return 0;
} 
