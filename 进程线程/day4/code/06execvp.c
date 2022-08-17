#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	
	printf("1111111111111\n");

	char *arg[] = {"ls", "-l", NULL};

	int ret = execvp("ls", arg);
	if(ret == -1)
	{
		perror("execvp");
		exit(-1);
	}

	printf("22222222222222\n");

	return 0;
}
