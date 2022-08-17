/*===============================================
*   文件名称：demo5.c
*   创 建 者：     
*   创建日期：2022年06月30日
*   描    述：
================================================*/
#include <stdio.h>
void maopao(int a[], int n)
{
    //sizeof(a)/sizeof(a[0]); //err a是数组的地址
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                a[j] ^= a[j+1];
                a[j+1] ^= a[j];
                a[j] ^= a[j+1];
            }
        }
    }
    /*
     * 验证a是否是一个变量
    int c = 10;
    a = &c;
    */
}

void arr_ptr(int *a, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    puts("");
}

int main(int argc, char *argv[])
{ 
    int a[5] = {-7, 9, 2, 3, 6};
    int b[7] = {1, -5, -9, 3, 9, 7, 0};

    puts("a:");
    arr_ptr(a, 5);
    puts("maopao a:");
    maopao(a, 5);
    arr_ptr(a, 5);
    puts("b:");
    arr_ptr(b, 7);
    puts("maopao b:");
    maopao(b, 7);
    arr_ptr(b, 7);
    return 0;
} 
