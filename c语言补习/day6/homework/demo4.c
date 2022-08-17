/*===============================================
*   文件名称：demo2.c
*   创 建 者：     
*   创建日期：2022年06月27日
*   描    述：
================================================*/
#include <stdio.h>

int main(int argc, char *argv[])
{ 
    char str[100], dst[100];
    printf("input str sting: ");
    gets(str);
    printf("input dst sting: ");
    gets(dst);
    int n;
    printf("input copy num: ");
    scanf("%d", &n);
    int i = 0, j = 0;
    while(str[i++]);
    i--;
    for(j; dst[j] && j < n; j++,i++)
        str[i] = dst[j];
    str[i] = '\0';
    puts(str);
    return 0;
} 
