/*===============================================
*   文件名称：main.c
*   创 建 者：     
*   创建日期：2022年07月14日
*   描    述：
================================================*/
#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{ 
    stack_t *head = stack_create();
    if (NULL == head)
    {
        printf("create failed!\n");
        return -1;
    }

    int n = 10;
    while (n--)
        stack_push(head, n+1);
    stack_display(head);
    n = 5;
    while (n--)
    {
        printf("top data: %d\n", stack_get_top(head));
        printf("pop data: %d\n", stack_pop(head));
    }
    stack_display(head);
    for (n = 10; n < 15; n++)
        stack_push(head, n+1);
    stack_display(head);


    stack_destory(head);
    head = NULL;

    return 0;
} 
