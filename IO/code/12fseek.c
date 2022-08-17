#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE *fp = fopen("./test.txt", "w");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}

	fputc('a', fp);

	fseek(fp, 0, SEEK_END);

	fseek(fp, 100, SEEK_END);

	fputc('b', fp);

	fclose(fp);

	return 0;
}
