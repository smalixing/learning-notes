#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE *fp = fopen("./1.txt", "r");
	if(NULL == fp)
	{
		perror("fopen");
		return -1;
	}

	char s[1024] = {0};

	int count = 0;

	while(1)
	{
		char *p = fgets(s, sizeof(s), fp);
		if(NULL == p)
		{
			perror("fgets");
			break;
		}
	
		printf("%s\n", p);

		count++;
	}

	printf("count=%d\n", count);

	fclose(fp);

	return 0;
}
