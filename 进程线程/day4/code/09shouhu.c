#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid == 0)
	{
		setsid(); //2.开启新的会话

		chdir("/tmp"); //3.改变工作目录

		umask(0);  //4.增加安全性

		close(0);
		close(1);
		close(2); //5.关闭文件描述符

		FILE *fp;
		while(1)
		{
			fp = fopen("/tmp/test.txt", "a");

			time_t t;
			time(&t);

			fprintf(fp, "%s", ctime(&t));

			fflush(fp);

			sleep(1);
		}
	}
	else{  //父进程
	
		exit(0); //1.父进程退出
	
	}


	return 0;
}
