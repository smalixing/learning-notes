/*===============================================
*   文件名称：main.c
*   创 建 者：     
*   创建日期：2022年07月15日
*   描    述：
================================================*/
#include <stdio.h>
#include "tree.h"

int main(int argc, char *argv[])
{ 
    tree_t *root = tree_create(1, 12);
    if (NULL == root)
    {
        printf("create failed!\n");
        return -1;
    }

    tree_DLR(root);
    printf("\n");
    tree_LDR(root);
    printf("\n");
    tree_LRD(root);
    printf("\n");

    return 0;
} 
