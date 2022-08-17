#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define N 100

struct msgbuf{
	long mtype;
	char mtext[N];
};

int main(int argc, const char *argv[])
{
	key_t key = ftok("/", 100);
	if(key==-1)
	{
		perror("ftok");
		return -1;
	}

	int msgid = msgget(key, IPC_CREAT|0666);
	if(msgid == -1)
	{
		perror("msgget");
		goto xxx;
	}

	printf("msgid:%d\n", msgid);

	system("ipcs -q");

	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork");
		goto  xxx;
	}
	else if(pid == 0)
	{
		//子进程  写
		struct msgbuf msg;
		
		char buf[64] = {0};

		while(1)
		{
			gets(buf);

			msg.mtype = 10;
			strcpy(msg.mtext , buf);

			msgsnd(msgid, &msg,sizeof(msg)-sizeof(long), 0);
		
			if(strncmp(buf, "quit", 4) == 0)
			{
				break;
			}
		}

	}
	else{
		//父进程 读
		waitpid(-1,NULL,WNOHANG);

		struct msgbuf msg;

		while(1)
		{
			msgrcv(msgid, &msg, sizeof(msg)-sizeof(long),10,0);
		
			printf("msg:%s\n", msg.mtext);
			
			if(strncmp(msg.mtext, "quit", 4) == 0)
			{
				break;
			}
			
		}
	}

	int ret = msgctl(msgid, IPC_RMID, NULL);
	if(ret == -1)
	{
		perror("msgctl");
		goto xxx;
	}

xxx:	
	sleep(2);

	char str[100] = {0};

	sprintf(str, "ipcrm -q %d", msgid);

	system(str);

	system("ipcs -q");

	return 0;
}
