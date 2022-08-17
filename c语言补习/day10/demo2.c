/*===============================================
*   文件名称：demo2.c
*   创 建 者：     
*   创建日期：2022年07月01日
*   描    述：
================================================*/
#include <stdio.h>
struct A{
    char a;
    int b;
};

struct B{
    char a;
    short b;
    int c;
};

struct C{
    char a;
    char b;
    short c;
    int d;
};

struct D{
    char a;
    short c;
    char b;
    int d;
};

struct F{
    char a;
    short c;
    double b;
    int d;
};
int main(int argc, char *argv[])
{ 
    struct A a;
    printf("%ld\n", sizeof a);
    struct B b;
    printf("%ld\n", sizeof b);
    struct C c;
    printf("%ld\n", sizeof c);
    struct D d;
    printf("%ld\n", sizeof d);
    struct F f;
    printf("%ld\n", sizeof f);
    return 0;
} 
