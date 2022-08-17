/*===============================================
*   文件名称：if1.c
*   创 建 者：     
*   创建日期：2022年06月22日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    float score;
    printf("please input your score: ");
    scanf("%f", &score);
    if(score >= 90 && score <= 100){
        puts("A");
    }else if(score >= 80 && score < 90){
        printf("B\n");
    }else if(score >= 70 && score < 80){
        puts("C");
    }else{
        puts("F");
    }

    return 0;
} 
