/*===============================================
*   文件名称：demo1.c
*   创 建 者：     
*   创建日期：2022年06月30日
*   描    述：
================================================*/
#include <stdio.h>
int add_arr(int m, int n, int a[][n])
{
    int sum = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
    }
    return sum;
}

int main(int argc, char *argv[])
{ 
    int a[2][3];
    int sum = add_arr(2, 3, a);
    return 0;
} 
