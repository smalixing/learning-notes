#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE *fp = fopen("./1.txt", "r");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}

	fseek(fp, 0, SEEK_END);

	int n = ftell(fp); //返回值：当前文件指针的位置

	printf("n=%d\n", n);


	rewind(fp);//文件指针移到开头

	n = ftell(fp);

	printf("n=%d\n", n);


	fclose(fp);

	return 0;
}
