/*===============================================
*   文件名称：stack.c
*   创 建 者：     
*   创建日期：2022年07月13日
*   描    述：
================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

node_t *stack_create()
{
    node_t *head = (node_t *)malloc(sizeof(node_t)); 
    if (NULL == head)
    {
        printf("malloc failed!\n");
        return NULL;
    }
    memset(head, 0, sizeof(node_t));
    head->next = NULL;
    return head;
}

void stack_destory(node_t *head)
{
    stack_clear(head);
    free(head);
}

void stack_clear(node_t *head)
{
    node_t *p = head->next;  //第一个有效节点
    node_t *q = NULL; 
    while (p != NULL)  //判断有效节点是否存在
    {
        q = p->next;  //先把下一个节点保存
        free(p);  //销毁p
        p = q;    //把下一个节点赋给p
    }
    head->next = NULL;  //把头节点指针域置空
}

int stack_isFull(node_t *head)
{
    return 0;
}

int stack_isEmpty(node_t *head)
{
    return (NULL == head->next) ? 1 : 0;
}

int stack_length(node_t *head)
{
    int len = 0;
    node_t *p = head->next; //p指向第一个有效节点
    while (p != NULL)  //判断节点是否存在
    { 
        len++;    
        p = p->next;  //p向下一个节点偏移
    }
    return len;
}

int stack_push(node_t *head, data_t data)
{
    //把data包装成节点p
    node_t *p = (node_t *)malloc(sizeof(node_t));
    if (NULL == p)
    {
        printf("malloc error, insert failed!\n");
        return -1;
    }
    p->data = data;
    p->next = NULL;
    
    node_t *q = head;
    //4. 把p插入节点q后面
    p->next = q->next;
    q->next = p;
    return 0;
}

data_t stack_pop(node_t *head)
{
    if (stack_isEmpty(head))
    {
        printf("stack is empty, pop failed!\n");
        return (data_t)-1;
    }
    //2. 找到删除节点q的前一节点p
    node_t *p = head;
    node_t *q = p->next;
    data_t data = q->data;
    //3. 删除节点q
    p->next = q->next;
    free(q);
    return data;
}

data_t stack_get_top(node_t *head)
{
    if (stack_isEmpty(head))
    {
        printf("stack is empty, no top data!\n");
        return (data_t)-1;
    }
    return head->next->data;
}

void stack_display(node_t *head)
{
    node_t *p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

