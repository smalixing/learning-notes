/*===============================================
*   文件名称：stack.c
*   创 建 者：     
*   创建日期：2022年07月14日
*   描    述：
================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

stack_t *stack_create()
{
    stack_t *head = (stack_t *)malloc(sizeof(stack_t));
    if (NULL == head)
    {
        printf("malloc error, create failed!\n");
        return NULL;
    }
    memset(head, 0, sizeof(stack_t));
    head->top = -1;
    return head;
}

void stack_destory(stack_t *head)
{
    free(head);
}

void stack_clear(stack_t *head)
{
    head->top = -1;
}

int stack_isFull(stack_t *head)
{
    return (SIZE-1 == head->top) ? 1 : 0;
}

int stack_isEmpty(stack_t *head)
{
    return (-1 == head->top) ? 1: 0;
}

int stack_push(stack_t *head, data_t data)
{
    if (stack_isFull(head))
    {
        printf("stack is full, push failed!\n");
        return -1;
    }
    head->data[head->top+1] = data;
    head->top++;
    return 0;
}

data_t stack_pop(stack_t *head)
{
    if (stack_isEmpty(head))
    {
        printf("stack is empty, pop failed!\n");
        return (data_t)-1;
    }
    data_t data = head->data[head->top];
    head->top--;
    return data;
}

data_t stack_get_top(stack_t *head)
{
    if (stack_isEmpty(head))
    {
        printf("stack is empty, no top data!\n");
        return (data_t)-1;
    }
    return head->data[head->top];
}

void stack_display(stack_t *head)
{
    int i;
    for (i = 0; i <= head->top; i++)
        printf("%d ", head->data[i]);
    printf("\n");
}

