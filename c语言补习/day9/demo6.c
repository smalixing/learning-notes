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
//typedef对类型取别名
typedef int (*Pfun)(int, int);   //Pfun == int (*)(int, int)

int main(int argc, char *argv[])
{ 
    Pfun p = add;
    printf("%d \n", p(2,3));
    printf("%d \n", (*p)(3,4));

    Pfun q = sub;
    printf("%d \n", q(2,3));
    printf("%d \n", (*q)(5,4));

    return 0;
} 
