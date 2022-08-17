#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

sem_t sem; //信号量

void *fun(void *arg)
{
	int n = 5;
	while(n--)
	{
		printf("xxxx\n");
		sleep(1);
	}

	sem_post(&sem);  //+1

}

int main(int argc, const char *argv[])
{
	//信号量的初始化
	sem_init(&sem, 0, 0);

	pthread_t tid;

	pthread_create(&tid, NULL, fun, NULL);
	pthread_detach(tid);
	
	printf("11111\n");

	sem_wait(&sem);  //-1

	printf("22222\n");

	while(1);

	return 0;
}
