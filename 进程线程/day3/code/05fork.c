#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	
	pid_t  pid; //进程号

	pid = fork();
	if(pid < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid == 0) //子进程
	{
		while(1)
		{
			printf("son is running!\n");
			sleep(2);
		}
	}
	else{ //父进程
	
		while(1)
		{
			printf("father is running!\n");
			sleep(2);
		}
		
	}

	return 0;
}
