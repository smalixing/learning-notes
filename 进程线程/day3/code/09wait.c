#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	pid_t pid;

	pid = fork();
	if(pid < 0)
	{
		perror("fork");
		exit(-1); //return -1
	}
	else if(pid == 0 )//子进程
	{
		int n = 5;

		while(n--)
		{
			printf("son is running!\n");
			sleep(1);
		}
	
		exit(15);
	}
	else{ //父进程

		int status;

		wait(&status);
		
		printf("%d\n", WEXITSTATUS(status)); //获取子进程的返回值

		printf("%d\n", WIFEXITED(status)); //判断子进程是否正常结束

		while(1);

	}


	return 0;
}
