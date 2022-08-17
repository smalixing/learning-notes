/*===============================================
*   文件名称：putchar.c
*   创 建 者：     
*   创建日期：2022年06月21日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    /*
    fclose(stdout);
    if(-1 == putchar(-1)){
        system("clear");
        sleep(2);
    }else{
        //sleep(1);
    }
    */
    int n = putchar('A');
    printf("ret:%d\n", n);

    return 0;
} 
