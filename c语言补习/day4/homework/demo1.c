/*===============================================
*   文件名称：demo1.c
*   创 建 者：     
*   创建日期：2022年06月23日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int y;
    printf("please input year: ");
    scanf("%d", &y);

    if(y % 4 == 0 && y % 100 != 0){
        puts("闰年");
    }else if(y % 100 == 0 && y % 400 == 0){
        puts("闰年");
    }else{
        puts("不是闰年");
    }
    return 0;
} 
