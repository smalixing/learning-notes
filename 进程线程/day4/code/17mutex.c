#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, value1, value2;

pthread_mutex_t mutex; //互斥锁的变量

void *fun1(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		i++;
		value1 = i;
		value2 = i;
		pthread_mutex_unlock(&mutex);
	}

}

void *fun2(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(value1 != value2)
		{
			printf("%d %d %d\n",i, value1, value2);		
		}
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc, const char *argv[])
{
	//初始化互斥锁
	pthread_mutex_init(&mutex, NULL);

	pthread_t tid1,tid2;

	pthread_create(&tid1, NULL, fun1, NULL);
	pthread_detach(tid1);

	pthread_create(&tid2, NULL, fun2, NULL);
	pthread_detach(tid2);

	while(1);

	return 0;
}
