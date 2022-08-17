/*===============================================
*   文件名称：switch.c
*   创 建 者：     
*   创建日期：2022年06月22日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    float score;
    printf("pilease input your score: ");
    scanf("%f", &score);
    int s = (int)score;
    s /= 10; // s = s / 10;
    switch(s){
        case 10:
            puts("A+");
            //break;
        case 9:
            puts("A");
            break;
        case 8:
            puts("B");
            break;
        case 7:
            puts("C");
            break;
        case 6:
            puts("D");
            break;
        default:
            puts("F");
    }

    return 0;
} 
