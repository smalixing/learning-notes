#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

char buf[100] = {0};

sem_t sem; //信号量

void *fun(void *arg)
{

	while(1)
	{
		sem_wait(&sem); //-1
		
		printf("%d\n", strlen(buf));
	}

}

int main(int argc, const char *argv[])
{
	//信号量的初始化
	sem_init(&sem, 0, 0);

	pthread_t tid;

	pthread_create(&tid, NULL, fun, NULL);
	pthread_detach(tid);
	

//	sem_wait(&sem);  //-1

	while(1)
	{
		gets(buf);	
	
		sem_post(&sem); //+1
	}

	return 0;
}
