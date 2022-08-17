/*===============================================
*   文件名称：for.c
*   创 建 者：     
*   创建日期：2022年06月22日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int i, sum = 0;
    for(i = 1; i <= 100; ){
        sum += i++; //sum = sum + i; i = i + 1;
    }
    //for(i = 1; i <= 100; sum += i++);
    printf("%d\n", sum);
    return 0;
} 
