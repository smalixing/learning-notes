/*===============================================
 *   文件名称：demo4.c
 *   创 建 者：     
 *   创建日期：2022年06月24日
 *   描    述：
 ================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    int a[5] = {1,2,3,4,5}, m, tmp;
    printf("please input move num: ");
    scanf("%d", &m);
    m %= 5;
    if(m < 0){
        m *= -1;  //m = -m;
        while(m--)
        {
            //向左循环移动1位
            tmp = a[0];
            for(int i = 0; i < 4; i++)
                a[i] = a[i+1];
            a[4] = tmp;
        }
    }else{
        while(m--)
        {
            //向右循环移动1位
            tmp = a[4];
            for(int i = 4; i > 0; i--)
                a[i] = a[i-1];
            a[0] = tmp;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
} 
