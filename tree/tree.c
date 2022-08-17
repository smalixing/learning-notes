/*===============================================
*   文件名称：tree.c
*   创 建 者：     
*   创建日期：2022年07月15日
*   描    述：
================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

tree_t *tree_create(int i, int n)
{
    tree_t *root = (tree_t *)malloc(sizeof(tree_t));
    if (NULL == root)
    {
        printf("malloc failed!\n");
        return NULL;
    }
    root->data = i;
    if (2*i <= n)
        root->lchild = tree_create(2*i, n);
    else
        root->lchild = NULL;
    if (2*i+1 <= n)
        root->rchild = tree_create(2*i+1, n);
    else
        root->rchild = NULL;
    return root;
}

void tree_DLR(tree_t *root)
{
    if (NULL == root)
        return;
    printf("%d ", root->data);
    tree_DLR(root->lchild);
    tree_DLR(root->rchild);
}

void tree_LDR(tree_t *root)
{
    if (NULL == root)
        return;
    tree_LDR(root->lchild);
    printf("%d ", root->data);
    tree_LDR(root->rchild);

}

void tree_LRD(tree_t *root)
{
    if (NULL == root)
        return;
    tree_LRD(root->lchild);
    tree_LRD(root->rchild);
    printf("%d ", root->data);

}
