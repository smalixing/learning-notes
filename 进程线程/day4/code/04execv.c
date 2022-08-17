#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	
	printf("1111111111111\n");

	char *arg[] = {"test", NULL};

	int ret = execv("./test", arg);
	if(ret == -1)
	{
		perror("execv");
		exit(-1);
	}

	printf("22222222222222\n");

	return 0;
}
