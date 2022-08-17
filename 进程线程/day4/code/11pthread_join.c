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

int main(int argc, const char *argv[])
{
	pthread_t tid; //线程号

	int ret = pthread_create(&tid, NULL, fun, NULL);
	if(ret == -1)
	{
		perror("pthread_create");
		return -1;
	}

	printf("aaaaaaaaaaa\n");

	pthread_join(tid, NULL);

	printf("bbbbbbbbbbbb\n");

	while(1);

	return 0;
}
