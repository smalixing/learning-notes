#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

sem_t sem1,sem2;

char buf[100] = {0};

int flag = 0;

int n = 0;

void *read_data(void *arg)
{
	//先读 从1.txt读取
	int fd = open("./1.txt", O_RDONLY);
	
	while(1)
	{
		sem_wait(&sem2);   //灯B -1
	//	printf("111111111111\n");
	//	sleep(1);
	
		n = read(fd, buf, sizeof(buf));
		if(n < 0)
		{
			perror("read");
			return NULL;
		}
		else if(n == 0)
		{
			flag = 1;
			close(fd);
			break;
		}	

		sem_post(&sem1);   //灯A +1
	}

}

void *write_data(void *arg)
{
	//再写到2.txt
	int fd = open("./2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

	while(1)
	{
		sem_wait(&sem1);   //灯A -1
		//printf("22222222222222\n");
		//sleep(1);
		
		write(fd, buf, n);
		
		if(flag == 1)
		{
			close(fd);
			break;
		}

		sem_post(&sem2);   //灯B +1
	}
}

int main(int argc, const char *argv[])
{
	sem_init(&sem1, 0, 0);  //灯A
	sem_init(&sem2, 0, 1);  //灯B

	pthread_t tid1,tid2;
	pthread_create(&tid1, NULL, read_data, NULL);
	pthread_detach(tid1);

	pthread_create(&tid2, NULL, write_data, NULL);
	pthread_detach(tid2);

	while(1);

	return 0;
}
