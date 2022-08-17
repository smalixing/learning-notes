/*===============================================
*   文件名称：demo2.c
*   创 建 者：     
*   创建日期：2022年06月30日
*   描    述：
================================================*/
#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);

int main(int argc, char *argv[])
{ 
    int a,b;
    char op;
    int (*p)(int, int);
    while(1)
    {
        scanf("%d %c %d", &a, &op, &b);
        switch(op){
            case '+':
                p = add;
                break;
            case '-':
                p = sub;
                break;
            case '*':
                p = mul;
                break;
            case '/':
                p = div;
                break;
            case '%':
                p = mod;
                break;
        }
        //printf("%d %c %d = %d\n", a, op, b, (*p)(a,b));
        printf("%d %c %d = %d\n", a, op, b, p(a,b));
    }
    return 0;
} 

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int mul(int a, int b)
{
    return a*b;
}

int div(int a, int b)
{
    return a/b;
}

int mod(int a, int b)
{
    return a%b;
}
