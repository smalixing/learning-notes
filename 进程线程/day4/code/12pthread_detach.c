#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//线程函数
void *fun(void *arg)
{
	int n = 5;

	while(n--)
	{
		printf("fun is running!\n");
		sleep(1);
	}

}

void *fun1(void *arg)
{
	int n = 8;

	while(n--)
	{
		printf("fun1 is running!\n");
		sleep(1);
	}

}

void *fun2(void *arg)
{
	int n = 12;

	while(n--)
	{
		printf("fun2 is running!\n");
		sleep(1);
	}

}

int main(int argc, const char *argv[])
{
	pthread_t tid, tid1, tid2; //线程号

	int ret = pthread_create(&tid, NULL, fun, NULL);
	if(ret == -1)
	{
		perror("pthread_create");
		return -1;
	}

	printf("aaaaaaaaaaa\n");

	//pthread_join(tid, NULL);
	pthread_detach(tid);


	pthread_create(&tid1, NULL, fun1, NULL);
	pthread_detach(tid1);


	pthread_create(&tid2, NULL, fun2, NULL);
	pthread_detach(tid1);

	
	
	printf("bbbbbbbbbbbb\n");

	while(1);

	return 0;
}
