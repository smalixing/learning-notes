/*===============================================
*   文件名称：linklist.c
*   创 建 者：     
*   创建日期：2022年07月13日
*   描    述：
================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

node_t *linklist_create()
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

void linklist_destory(node_t *head)
{
    linklist_clear(head);
    free(head);
}

void linklist_clear(node_t *head)
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

int linklist_isFull(node_t *head)
{
    return 0;
}

int linklist_isEmpty(node_t *head)
{
    return (NULL == head->next) ? 1 : 0;
}

int linklist_length(node_t *head)
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

int linklist_insert(node_t *head, int pos, data_t data)
{
    //1. 判断pos是否有效，无效则报错返回
    int len = linklist_length(head);
    if ((pos < 0) || (pos > len))
    {
        printf("pos is invalid, insert failed!\n");
        return -1;
    }
    //2. 把data包装成节点p
    node_t *p = (node_t *)malloc(sizeof(node_t));
    if (NULL == p)
    {
        printf("malloc error, insert failed!\n");
        return -1;
    }
    p->data = data;
    p->next = NULL;
    //3. 找到要插入位置的前一个节点q
    node_t *q = head;
    while (pos--)
        q = q->next;
    //4. 把p插入节点q后面
    p->next = q->next;
    q->next = p;
    return 0;
}

int linklist_pos_delete(node_t *head, int pos)
{
    //1. 判断pos位置是否有效
    int len = linklist_length(head);
    if ((pos < 0) || (pos >= len))
    {
        printf("pos is invalid, delete failed!\n");
        return -1;
    }
    //2. 找到删除节点q的前一节点p
    node_t *p = head;
    node_t *q = NULL;
    while (pos--)
        p = p->next;
    q = p->next;
    //3. 删除节点q
    p->next = q->next;
    free(q);
    return 0;
}

int linklist_data_delete(node_t *head, data_t data)
{
    //1. 找到删除数据data的位置pos
    int pos = 0;
    node_t *p = head->next;
    while (p != NULL)
    {
        if (p->data == data)
            break;
        pos++;
        p = p->next;
    }
    if (NULL == p)
    {
        printf("No such data, delete failed!\n");
        return -1;
    }
    //2. 调用posDelete删除数据
    linklist_pos_delete(head, pos);
    return 0;
}

int linklist_pos_update(node_t *head, int pos, data_t data)
{
    int len = linklist_length(head);
    if ((pos < 0) || (pos >= len))
    {
        printf("pos is invalid, update failed!\n");
        return -1;
    }
    node_t *p = head->next;
    while (pos--)
        p = p->next;
    p->data = data;
    return 0;
}

int linklist_data_update(node_t *head, data_t old_data, data_t new_data)
{
    node_t *p = linklist_data_search(head, old_data);
    if (NULL == p)
    {
        printf("No such data, update failed!\n");
        return -1;
    }
    p->data = new_data;
    return 0;
}

data_t linklist_pos_search(node_t *head, int pos)
{
    int len = linklist_length(head);
    if ((pos < 0) || (pos >= len))
    {
        printf("pos is invalid, search failed!\n");
        return (data_t)-1;
    }
    node_t *p = head->next;
    while (pos--)
        p = p->next;
    return p->data;
}

node_t *linklist_data_search(node_t *head, data_t data)
{
    node_t *p = head->next;
    while (p != NULL)
    {
        if (p->data == data)
            return p;
        p = p->next;
    }
    printf("No such data, search failed!\n");
    return NULL;
}

void linklist_display(node_t *head)
{
    node_t *p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void linklist_invert(node_t *head)
{
    node_t *p = head->next;
    node_t *q = NULL;
    //把链表断开成两个链表，一个只有头，一个只有有效节点
    head->next = NULL;
    //遍历所有的有效节点，使用头插法插入到只有头的链表中
    while (p != NULL)
    {
        q = p->next;
        //头插法：把p插入到head后面
        p->next = head->next;
        head->next = p;
        p = q;
    }
}

void linklist_sort(node_t *head)
{
    node_t *p = head->next; //第一个有效节点
    node_t *q = NULL; //p的下一个节点
    node_t *t = NULL; //要插入位置的前一个节点
    node_t *r = NULL; //要插入位置的节点
    head->next = NULL;  //断开链表为两个链表
    //遍历无序链表，把每一个节点在有序链表中找到相应位置插入
    while (p != NULL) 
    {
        q = p->next; //先保存p的下一个节点
        //从head开始找到有序链表中要插入位置的前一节点t
        t = head;    
        r = t->next;
        //当插入位置r存在且p值大于r值时，则t，r都后移一个节点
        while (r != NULL && p->data > r->data)
        {
            t = r;
            r = t->next;
        }
        //把p插入t后面
        p->next = r;
        t->next = p;
        //再插入下一个节点
        p = q;
    }
}
