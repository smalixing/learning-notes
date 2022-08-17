#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	int fd[2];

	int ret = pipe(fd);
	if(ret == -1)
	{
		perror("pipe");
		return -1;
	}

	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork");
		return -1; //exit(-1);
	}
	else if(pid == 0)
	{
		//写操作
		close(fd[0]);

		char buf[100] = {0};
		while(1)
		{
			gets(buf);

			write(fd[1], buf, strlen(buf));
		}

	}
	else{
		//读操作	
		close(fd[1]);

		char buf[100] ={0};
	
		while(1)
		{
			read(fd[0], buf, sizeof(buf));

			printf("%s\n", buf);

			memset(buf, 0 , 100);
		}
	}

	return 0;
}
