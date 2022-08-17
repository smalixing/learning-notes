/*===============================================
*   文件名称：linklist.h
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

node_t *linklist_create();
void linklist_destory(node_t *head);

void linklist_clear(node_t *head);
int linklist_isFull(node_t *head);
int linklist_isEmpty(node_t *head);
int linklist_length(node_t *head);

int linklist_insert(node_t *head, int pos, data_t data);
int linklist_pos_delete(node_t *head, int pos);
int linklist_data_delete(node_t *head, data_t data);
int linklist_pos_update(node_t *head, int pos, data_t data);
int linklist_data_update(node_t *head, data_t old_data, data_t new_data);
data_t linklist_pos_search(node_t *head, int pos);
node_t *linklist_data_search(node_t *head, data_t data);

//实现链表的倒置
void linklist_invert(node_t *head);
void linklist_sort(node_t *head);
void linklist_display(node_t *head);

#endif
