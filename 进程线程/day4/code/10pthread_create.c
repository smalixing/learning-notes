#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//线程函数
void *fun(void *arg)
{

	while(1)
	{
		printf("fun is running!\n");
		sleep(2);
	}

}

int main(int argc, const char *argv[])
{
	pthread_t tid; //线程号

	int ret = pthread_create(&tid, NULL, fun, NULL);
	if(ret == -1)
	{
		perror("pthread_create");
		return -1;
	}

	while(1)
	{
		printf("main is running!\n");
		sleep(2);
	}


	return 0;
}
