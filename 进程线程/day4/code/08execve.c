#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	
	printf("1111111111111\n");

	char *arg[] = {"test", NULL};

	//设置环境变量
	char *envp[] = {"PATH=.", NULL};

	int ret = execve("./test", arg , envp);
	if(ret == -1)
	{
		perror("execve");
		exit(-1);
	}

	printf("22222222222222\n");

	return 0;
}
