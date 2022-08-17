/*===============================================
*   文件名称：queue.c
*   创 建 者：     
*   创建日期：2022年07月15日
*   描    述：
================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

queue_t *queue_create()
{
    //创建队列queue
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    if (NULL == queue)
    {
        printf("malloc failed!\n");
        return NULL;
    }
    //创建头节点
    node_t *head = (node_t *)malloc(sizeof(node_t));
    if (NULL == head)
    {
        free(queue);
        printf("malloc failed!\n");
        return NULL;
    }
    head->next = NULL;
    //空队，让队头和队尾指向head
    queue->front = head;
    queue->rear = head;
    return queue;
}

void queue_destory(queue_t *queue)
{
    queue_clear(queue);
    free(queue->front);
    free(queue);
}

void queue_clear(queue_t *queue)
{
    //找到第一个有效节点
    node_t *p = queue->front->next;
    node_t *q = NULL;
    //遍历所有的有效节点并free
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    //把头节点指针域设为NULL
    queue->front->next = NULL;
    //把尾节点指向头节点
    queue->rear = queue->front;
}

int queue_isFull(queue_t *queue)
{
    return 0;
}

int queue_isEmpty(queue_t *queue)
{
    return (queue->front == queue->rear) ? 1 : 0;
}

//入队
int queue_en(queue_t *queue, data_t data)
{
    //1. 把data包装成节点p
    node_t *p = (node_t *)malloc(sizeof(node_t));
    if (NULL == p)
    {
        printf("malloc error, entry failed!\n");
        return -1;
    }
    p->data = data;
    p->next = NULL;
    //2. 直接把p插入到队尾rear后面
    queue->rear->next = p;
    //3. 队尾rear指向p
    queue->rear = p;
    return 0;
}

//出队
data_t queue_de(queue_t *queue)
{
    //1. 判断队列是否为空队，空队则报错返回
    if (queue_isEmpty(queue))
    {
        printf("queue is empty, delete failed!\n");
        return (data_t)-1;
    }
    //2. 删除front后的第一个有效节点p
    node_t *head = queue->front; //头节点 
    node_t *p = head->next;  //要删除的第一个有效节点
    //删除head的下一个节点p
    head->next = p->next; 
    data_t data = p->data;
    free(p);
    //3. 判断删除的是否是最后一个有效节点，如果是则rear指向头节点
    if (NULL == head->next)
        queue->rear = head;
    return data;
}

void queue_display(queue_t *queue)
{
    node_t *p = queue->front->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
