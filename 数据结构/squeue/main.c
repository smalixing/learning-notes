/*===============================================
*   文件名称：main.c
*   创 建 者：     
*   创建日期：2022年07月15日
*   描    述：
================================================*/
#include <stdio.h>
#include "queue.h"

int main(int argc, char *argv[])
{ 
    queue_t *head = queue_create();
    if (NULL == head)
    {
        printf("create failed!\n");
        return -1;
    }
    int i, n;
    for (i = 1; i <= 3; i++)
        queue_en(head, i);
    queue_display(head);
    n = 3;
    while (n--)
        printf("de: %d\n", queue_de(head));
    queue_display(head);
    for (i = 1; i <= 8; i++)
        queue_en(head, i);
    queue_display(head);
    
    
    queue_destory(head);
    head = NULL;

    return 0;
} 
