/*===============================================
*   文件名称：demo2.c
*   创 建 者：     
*   创建日期：2022年06月28日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int a[3][4] = {-2,3,10,9,4,2,0,-7,5,3,1,6};

    for(int i = 0; i < 3; i++)
    {
        for(int n = 0; n < 3; n++)
        {
            for(int j = 0; j < 3-n; j++)
            {
                if(a[i][j] < a[i][j+1])
                {
                    a[i][j] ^= a[i][j+1];
                    a[i][j+1] ^= a[i][j];
                    a[i][j] ^= a[i][j+1];
                }
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
} 
