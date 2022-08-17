/*===============================================
*   文件名称：if.c
*   创 建 者：     
*   创建日期：2022年06月22日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int IQ;
    printf("please input your IQ: ");
    scanf("%d", &IQ);
    if(IQ > 250){
        puts("恭喜你,你比250聪明一丢丢!");
    }else{
        puts("你连250都不如^-^!!!!");
    }
    return 0;
} 
