/*===============================================
*   文件名称：demo1.c
*   创 建 者：     
*   创建日期：2022年06月27日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int a[3][4], max, x = 0, y = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("input a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    max = a[0][0];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(max < a[i][j])
            {
                max = a[i][j];
                x = i;
                y = j;
            }
        }
    }

    printf("max:%d x:%d y:%d\n", max, x, y);
    return 0;
} 
