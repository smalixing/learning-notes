#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//线程函数
void *fun(void *arg)
{

	while(1)
	{
		printf("fun is running!\n");
		sleep(1);
	}

}

int main(int argc, const char *argv[])
{
	pthread_t tid; //线程号

	pthread_create(&tid, NULL, fun, NULL);
	pthread_detach(tid);

	char buf[10] = {0};

	while(1)
	{
		gets(buf);
		
		if(strncmp(buf, "q", 1) == 0)
		{
			pthread_cancel(tid);
		}	
		
		if(strncmp(buf, "Q", 1) == 0)
		{
			exit(0);
		}
	}

	return 0;
}
