#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	
	printf("1111111111111\n");


	//设置环境变量
	char *envp[] = {"PATH=.", NULL};

	int ret = execle("./test", "test" , NULL,  envp);
	if(ret == -1)
	{
		perror("execle");
		exit(-1);
	}

	printf("22222222222222\n");

	return 0;
}
