#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE *fp = fopen("./1.txt", "rb");
	if(NULL ==fp)
	{
		perror("fopen");
		return -1;
	}

	char buf[100] = {0};

	//int n = fread(buf, 10, 10, fp);
	//int n = fread(buf, 20, 5, fp);
	int n = fread(buf, 4, 25, fp);

	printf("n=%d\n", n);

	printf("buf:%s\n", buf);

	fclose(fp);

	return 0;
}
