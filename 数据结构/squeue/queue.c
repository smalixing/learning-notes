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
    queue_t *head = (queue_t *)malloc(sizeof(queue_t));
    if (NULL == head)
    {
        printf("malloc failed!\n");
        return NULL;
    }
    memset(head, 0, sizeof(queue_t));
    head->front = 0;
    head->rear = 0;
    return head;
}

void queue_destory(queue_t *head)
{
    free(head);
}

void queue_clear(queue_t *head)
{
    head->front = head->rear = 0;
}

int queue_isFull(queue_t *head)
{
    return (SIZE == head->rear - head->front) ? 1 : 0;
}

int queue_isEmpty(queue_t *head)
{
    return (head->rear == head->front) ? 1 : 0;
}

//入队
int queue_en(queue_t *head, data_t data)
{
    if (queue_isFull(head))
    {
        printf("queue is full, enter failed!\n");
        return -1;
    }
    head->data[head->rear % SIZE] = data;
    head->rear++;
    return 0;
}

//出队
data_t queue_de(queue_t *head)
{
    if (queue_isEmpty(head))
    {
        printf("queue is empty, delete failed!\n");
        return (data_t)-1;
    }
    data_t data = head->data[head->front % SIZE];
    head->front++;
    //当出队到SIZE时，rear和front重新回到数组下标对应位置
    if (SIZE == head->front)
    {
        head->front = 0;
        head->rear = head->rear % SIZE;
    }
    return data;
}

void queue_display(queue_t *head)
{
    int i;
    for (i = head->front; i < head->rear; i++)
        printf("%d ", head->data[i % SIZE]);
    printf("\n");
}
