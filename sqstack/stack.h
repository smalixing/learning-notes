/*===============================================
*   文件名称：stack.h
*   创 建 者：     
*   创建日期：2022年07月14日
*   描    述：
================================================*/
#ifndef __STACK_H__
#define __STACK_H__

#define SIZE 100
typedef int data_t;

typedef struct {
     data_t data[SIZE];
     int top;   //栈顶指针，最后一个有效元素下标
}stack_t;

stack_t *stack_create();
void stack_destory(stack_t *head);
void stack_clear(stack_t *head);
int stack_isFull(stack_t *head);
int stack_isEmpty(stack_t *head);
//在栈顶入栈
int stack_push(stack_t *head, data_t data);
//在栈顶出栈
data_t stack_pop(stack_t *head);
//获取栈顶元素
data_t stack_get_top(stack_t *head);
void stack_display(stack_t *head);

#endif

