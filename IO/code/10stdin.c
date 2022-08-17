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

	char buf[100] = {0};

	while(1)
	{
		char *p = fgets(buf, sizeof(buf), stdin);
		if(NULL == p)
		{
			perror("fgets");
			break;
		}

		if( strncmp(buf, "quit", 4)  == 0)
		{
			break;
		}

		int	n = fputs(buf, fp);

		printf("n = %d\n", n);

		memset(buf, 0, sizeof(buf));
	}

	fclose(fp);

	return 0;
}
