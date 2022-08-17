#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	//1.输入命令

	char buf[100] = {0};
	char *arg[100] = {NULL};
	char *p;

	while(1)
	{
		//printf("输入命令: ");
	
		//fflush(stdout);

		gets(buf);

		arg[0] = strtok(buf, " ");
	
		//printf("%s\n", arg[0]);
	
		int i = 1;
		while( (p  = strtok(NULL, " ")) != NULL)
		{
			arg[i] = p;
			i++;
		}

		pid_t pid = fork();
		if(pid < 0)
		{
			perror("fork");
			exit(-1);
		}
		else if(pid == 0) //子进程
		{
			//重生
			execvp(arg[0], arg);

		}
		else{
		//	wait(NULL);
			waitpid(-1, NULL, WNOHANG);
		}

		memset(buf, 0, 100);
	}

	return 0;
}
