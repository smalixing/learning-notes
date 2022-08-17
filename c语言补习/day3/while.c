/*===============================================
*   文件名称：while.c
*   创 建 者：     
*   创建日期：2022年06月22日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int sum = 1;
    int num = 5;
    /*
    while(num){
        sum *= num;
        num--;
    }
    */
    while(num--){
        sum *= num + 1;
    }
    printf("sum:%d\n", sum);
    return 0;
} 
