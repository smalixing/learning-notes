/*===============================================
*   文件名称：queue.h
*   创 建 者：     
*   创建日期：2022年07月15日
*   描    述：
================================================*/
#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef int data_t;
typedef struct node{
    data_t data;
    struct node *next;
}node_t;  //节点类型

typedef struct {
    node_t *front;  //头节点的地址
    node_t *rear;   //尾节点的地址
}queue_t;

queue_t *queue_create();
void queue_destory(queue_t *queue);
void queue_clear(queue_t *queue);
int queue_isFull(queue_t *queue);
int queue_isEmpty(queue_t *queue);
//入队
int queue_en(queue_t *queue, data_t data);
//出队
data_t queue_de(queue_t *queue);

void queue_display(queue_t *queue);


#endif
