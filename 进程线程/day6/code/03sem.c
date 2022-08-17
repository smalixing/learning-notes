#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

union semun {
	int val;  /* Value for SETVAL */
	struct semid_ds *buf;  
	unsigned short  *array;
	struct seminfo  *__buf; 
};

/*
struct sembuf{
	unsigned short sem_num;
	short sem_op;
	short sem_flg;
};
*/

int main(int argc, const char *argv[])
{
	key_t key = ftok("/", 1);
	if(key == -1)
	{
		perror("ftok");
		return -1;
	}

 	int shmid = shmget(key, 1024, IPC_CREAT|0666);
	if(shmid == -1)
	{
		perror("shmget");
		goto xxx;
	}

	printf("shmid:%d\n",shmid);

	system("ipcs -m"); 

	char *p = shmat(shmid, NULL, 0);
	if(p == NULL)
	{
		perror("shmat");
		goto xxx;
	}


	//加入信号灯集来控制共享内存
	int semid = semget(key, 2, IPC_CREAT|0666);
	if(semid == -1)
	{
		perror("semget");
		goto xxx;
	}

	//设置初值
	union semun sem0 = {0};
	union semun sem1 = {1};

	//设置编号
	semctl(semid, 0, SETVAL, sem0);
	semctl(semid, 1, SETVAL, sem1);

	//fork
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork");
		goto xxx;
	}
	else if(pid == 0)
	{
		//子进程 写操作
	
		char buf[64] = {0};
		
		struct sembuf sem0;
		sem0.sem_num = 1; //编号
		sem0.sem_op = -1; //PV操作 +1 -1
		sem0.sem_flg = 0;

		struct sembuf sem1;
		sem1.sem_num = 0;
		sem1.sem_op = 1;
		sem1.sem_flg = 0;

		while(1)
		{
			semop(semid, &sem0, 1);

			gets(buf);

			strcpy(p, buf);

			if(strncmp(buf, "quit", 4) == 0)
			{
				break;
			}

			semop(semid, &sem1, 1);
		}

	}
	else{
		//父进程 读操作
		waitpid(-1, NULL, WNOHANG);

		struct sembuf sem0;
		sem0.sem_num = 0;
		sem0.sem_op = -1;
		sem0.sem_flg = 0;

		struct sembuf sem1;
		sem1.sem_num = 1;
		sem1.sem_op = 1;
		sem1.sem_flg = 0;
		
		while(1)
		{
			semop(semid, &sem0, 1);

			printf("p=%s\n", p);
			sleep(1);
		
			if(strncmp(p, "quit", 4) == 0)
			{
				break;
			}

			semop(semid, &sem1, 1);
		}
	
	}

	int ret = semctl(semid, 0|1, IPC_RMID);
	if(ret == -1)
	{
		perror("semctl");
		goto xxx;
	}

	ret = shmdt(p);
	if(ret == -1)
	{
		perror("shmdt");
		goto xxx;
	}

	ret = shmctl(shmid, IPC_RMID, NULL);
	if(ret == -1)
	{
		perror("shmctl");
		goto xxx;
	}

xxx:	
	sleep(2); //防止出错

	char str[100] = {0};

	sprintf(str, "ipcrm -m %d", shmid);

	system(str);

	system("ipcs -m");

	return 0;
}
