/*===============================================
*   文件名称：tree.h
*   创 建 者：     
*   创建日期：2022年07月15日
*   描    述：
================================================*/
#ifndef __TREE_H__
#define __TREE_H__

typedef int data_t;

typedef struct node{
    data_t data;
    struct node *lchild;
    struct node *rchild;
}tree_t;

//创建完全二叉树，树根编号i=1，总共节点数
tree_t *tree_create(int i, int n);

void tree_DLR(tree_t *root);
void tree_LDR(tree_t *root);
void tree_LRD(tree_t *root);

#endif

