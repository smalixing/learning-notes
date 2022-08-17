#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE *fp = fopen("./a.txt", "w");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}

	fprintf(fp, "%d-%d-%d %d:%d:%d\n", 2022,7,21,11,23,30);

	fclose(fp);

	return 0;
}
