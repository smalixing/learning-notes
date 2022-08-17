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

		//阻塞
		//waitpid(-1, NULL, 0);

		//sleep(15);	

		//非阻塞
		waitpid(-1, NULL, WNOHANG);
		
		while(1)
		{
			printf("xxxx\n");
			sleep(1);
		}

	}


	return 0;
}
