/*===============================================
*   文件名称：const_value.c
*   创 建 者：     
*   创建日期：2022年06月30日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    const int a = 10;
    //a = 30; //err
    int *p = (int *)&a;
    *p = 20;
    printf("a:%d\n", a);
    return 0;
} 
