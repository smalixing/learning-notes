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
    queue_t *queue = queue_create();
    if (NULL == queue)
    {
        printf("create failed!\n");
        return -1;
    }
    int i, n;
    for (i = 1; i <= 3; i++)
        queue_en(queue, i);
    queue_display(queue);
    n = 3;
    while (n--)
        printf("de: %d\n", queue_de(queue));
    queue_display(queue);
    for (i = 1; i <= 8; i++)
        queue_en(queue, i);
    queue_display(queue);
    
    
    queue_destory(queue);
    queue = NULL;

    return 0;
} 
