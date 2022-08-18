/*===============================================
*   文件名称：hash_search.c
*   创 建 者：     
*   创建日期：2022年07月18日
*   描    述：
================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int data_t;

typedef struct node{
    data_t data;
    struct node *next;
}node_t;

void hash_create(data_t *data, int size, node_t *hp[], int n)
{
    int i, pos;
    for (i = 0; i < size; i++)
    {
        node_t *p = (node_t *)malloc(sizeof(node_t));
        memset(p, 0, sizeof(node_t));
        p->data = data[i];
        p->next = NULL;
        
        pos = data[i] % n;
        if (NULL == hp[pos])
            hp[pos] = p;
        else
        {
            p->next = hp[pos];
            hp[pos] = p;
        }
    }
}

void hash_display(node_t *hp[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d: ", i);
        node_t *p = hp[i];
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{ 
    data_t data[11] = {23, 34, 14, 38, 46, 16, 68, 15, 7, 31, 26};
    node_t *hp[13] = {NULL};
    hash_create(data, 11, hp, 13);
    hash_display(hp, 13);

    return 0;
} 
