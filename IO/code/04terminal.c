#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE *fp = fopen("/dev/pts/3", "w");
	if(NULL == fp)
	{
		perror("fopen");
		return -1;
	}

	int n = 10;
	while(1)
	{
		fputc('x', fp);

		//sleep(1);
	}

	fclose(fp);

	return 0;
}
