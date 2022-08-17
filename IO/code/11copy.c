#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	if(argc!=3)
	{
		printf("%s src_file dest_file\n", argv[0]);
		return -1;
	}

	FILE *fp1 = fopen( argv[1] ,  "r");
	if(fp1 == NULL)
	{
		perror("fopen");
		return -1;
	}
	
	FILE *fp2 = fopen( argv[2] ,  "w");
	if(fp2 == NULL)
	{
		perror("fopen");
		return -1;
	}

	char buf[1024] = {0};

	while(1)
	{
		char *p = fgets(buf, sizeof(buf), fp1);
		if(p == NULL)
		{
			break;
		}
	
		fputs(buf, fp2);
	
		memset(buf, 0 ,sizeof(buf));
	}

	printf("copy success!\n");

	fclose(fp1);
	fclose(fp2);

	return 0;
}
