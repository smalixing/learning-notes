#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, const char *argv[])
{
	int count = 0;

	FILE *fp;

	while(1)
	{
		fp = fopen("./1.txt", "w+");
		if(NULL == fp)
		{
			//printf("errno: %s\n", strerror(errno));
			perror("fopen");
			//return -1;
			break;
		}

		printf("%p\n", fp);

		count++;
	}

	printf("count=%d\n", count);

#if 0	
	printf("%d\n", argc);
	printf("%s\n", argv[0]);
	printf("%s\n", argv[1]);
	printf("%s\n", argv[2]);
#endif
	return 0;
}
