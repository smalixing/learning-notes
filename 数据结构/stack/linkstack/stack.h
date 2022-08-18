/*===============================================
*   文件名称：stack.h
*   创 建 者：     
*   创建日期：2022年07月13日
*   描    述：
================================================*/
#ifndef __LINKLIST_H__
#define __LINKLIST_H__

typedef int data_t;

typedef struct node{
    data_t data;   //数据域
    struct node *next; //指针域：指向下一个节点
}node_t;

node_t *stack_create();
void stack_destory(node_t *head);

void stack_clear(node_t *head);
int stack_isFull(node_t *head);
int stack_isEmpty(node_t *head);
int stack_length(node_t *head);

int stack_push(node_t *head, data_t data);
data_t stack_pop(node_t *head);
data_t stack_get_top(node_t *head);

void stack_display(node_t *head);

#endif
