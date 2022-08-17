#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fun(void)
{
	printf("aaaaaaa");

	exit(0);
}

int main(int argc, const char *argv[])
{

	printf("111111\n");

	fun();

	printf("222222\n");

	return 0;
}
