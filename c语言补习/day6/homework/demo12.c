/*===============================================
*   文件名称：demo12.c
*   创 建 者：     
*   创建日期：2022年06月27日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int num, count[5] = {0};
    while(1)
    {
        printf("please input 0-4: ");
        scanf("%d", &num);
        if(-1 == num)
            break;
        count[num]++;
    }

    for(int i = 0; i < 5; i++)
        printf("%d input num = %d\n", i, count[i]);
    return 0;
} 
