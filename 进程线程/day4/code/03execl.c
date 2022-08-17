#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	
	printf("1111111111111\n");

	int ret = execl("./test", "test", NULL);
	if(ret == -1)
	{
		perror("execl");
		exit(-1);
	}

	printf("22222222222222\n");

	return 0;
}
