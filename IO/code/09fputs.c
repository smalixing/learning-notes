#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE *fp = fopen("./2.txt", "a+");
	if(NULL == fp)
	{
		perror("fopen");
		return -1;
	}

	char buf[100] = "hello world\n";

	int n = fputs(buf, fp);

	printf("n = %d\n", n);

	fclose(fp);

	return 0;
}
