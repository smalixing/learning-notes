/*===============================================
*   文件名称：main.c
*   创 建 者：     
*   创建日期：2022年07月12日
*   描    述：
================================================*/
#include <stdio.h>
#include "linklist.h"

int main(int argc, char *argv[])
{ 
    node_t *head = linklist_create();
    if (NULL == head)
    {
        printf("create linklist failed!\n");
        return -1;
    }
    printf("head = %p\n", head);

    int n = 12;
    while (n--)
    {
        if (-1 == linklist_insert(head, 0, n+1))
            break;
    }
    linklist_display(head);

    printf("5's pos: %p\n", linklist_data_search(head, 10));
    printf("5's data: %d\n", linklist_pos_search(head, 5));
    linklist_data_update(head, 5, 100);
    linklist_pos_update(head, 3, 1000);
    linklist_display(head);
    linklist_pos_delete(head, 0);
    linklist_pos_delete(head, 10);
    linklist_data_delete(head, 100);
    linklist_display(head);
    linklist_insert(head, 0, 90);
    linklist_insert(head, 4, 50);
    linklist_insert(head, 8, 50);
    linklist_display(head);
    linklist_sort(head);
    linklist_display(head);
    linklist_invert(head);
    linklist_display(head);

    linklist_destory(head);
    head = NULL;

    return 0;
} 
