/*===============================================
*   文件名称：queue.h
*   创 建 者：     
*   创建日期：2022年07月15日
*   描    述：
================================================*/
#ifndef __QUEUE_H__
#define __QUEUE_H__

#define SIZE 7
typedef int data_t;

typedef struct {
    data_t data[SIZE];
    int front;
    int rear;
}queue_t;

queue_t *queue_create();
void queue_destory(queue_t *head);
void queue_clear(queue_t *head);
int queue_isFull(queue_t *head);
int queue_isEmpty(queue_t *head);
//入队
int queue_en(queue_t *head, data_t data);
//出队
data_t queue_de(queue_t *head);

void queue_display(queue_t *head);

#endif
