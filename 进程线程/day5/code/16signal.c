#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

//信号处理函数
void handler(int signum)
{
	if(signum == SIGQUIT)
	{
		printf("笑脸\n");
	}
	else if(signum == SIGTSTP)
	{
		printf("哭脸\n");
	}
}

int main(int argc, const char *argv[])
{

	//1. 忽略ctrl+c信号
	//signal(SIGINT, SIG_IGN);

	//2. 默认
	//singal(SIGINT, SIG_DFL);

	//3.自定义的信号处理函数
	signal(SIGQUIT, handler);
	signal(SIGTSTP, handler);

	while(1)
	{
		printf("---\n");
		sleep(1);
	}

	return 0;
}
