/*===============================================
*   文件名称：demo2.c
*   创 建 者：     
*   创建日期：2022年06月23日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int a[5] = {1,2,3,4,5}, tmp;
    for(int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    puts("");

    //1、用tmp保存最后一个元素的值
    tmp = a[4];
    //2、将数组元素依次向右移动1位
    for(int i = 4; i > 0; i--){
        a[i] = a[i-1];
    }
    //3、将tmp保存的值赋值给a[0]
    a[0] = tmp;
    for(int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    puts("");

    return 0;
} 
