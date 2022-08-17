/*===============================================
*   文件名称：demo5.c
*   创 建 者：     
*   创建日期：2022年06月30日
*   描    述：
================================================*/
#include <stdio.h>
int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int main(int argc, char *argv[])
{ 
    int (*pfun)(int, int) = add;
    printf("%d \n", pfun(2,3));
    printf("%d \n", (*pfun)(3,4));

    pfun = sub;
    printf("%d \n", pfun(2,3));
    printf("%d \n", (*pfun)(5,4));

    return 0;
} 
