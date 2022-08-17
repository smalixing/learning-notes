/*===============================================
*   文件名称：demo4.c
*   创 建 者：     
*   创建日期：2022年06月30日
*   描    述：
================================================*/
#include <stdio.h>
int *mydate()
{
    static int date[3];
    printf("please input yy-mm-dd: ");
    scanf("%d %d %d", &date[0], &date[1], &date[2]);
    return date;
}

void date_show(int *date)
{
    printf("date: %d/%d/%d\n", date[0], date[1], date[2]);
}

int main(int argc, char *argv[])
{ 
    int *d = mydate();
    date_show(d);
    return 0;
} 
