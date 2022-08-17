#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

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

		while(1)
		{
			gets(buf);

			strcpy(p, buf);

			if(strncmp(buf, "quit", 4) == 0)
			{
				break;
			}
		}

	}
	else{
		//父进程 读操作
		waitpid(-1, NULL, WNOHANG);

		while(1)
		{
			printf("p=%s\n", p);
			sleep(1);
		
			if(strncmp(p, "quit", 4) == 0)
			{
				break;
			}	
		}
	
	}

	int ret = shmdt(p);
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
