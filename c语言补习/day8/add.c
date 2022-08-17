/*===============================================
*   文件名称：add.c
*   创 建 者：     
*   创建日期：2022年06月29日
*   描    述：
================================================*/
#include <stdio.h>
//声明函数
//a, b是形参
int add(int a, int b);

int main(int argc, char *argv[])
{ 
    //int a = 1, int b = 2;
    //1,2是实参
    int sum = add(1,2);
    return 0;
} 

//函数的实现
int add(int a, int b)
{
    //int sum = a+b;
    //return sum;
    return a+b;
}
