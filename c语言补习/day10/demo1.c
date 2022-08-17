/*===============================================
*   文件名称：demo1.c
*   创 建 者：     
*   创建日期：2022年07月01日
*   描    述：
================================================*/
#include <stdio.h>
int fun(int n)
{
	if(n == 1)
		return 1;
	 return n*fun(n-1);	
}
int main(int argc, char *argv[])
{ 
    printf("%d\n", fun(3));
    return 0;
} 
