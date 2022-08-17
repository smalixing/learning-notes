#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main(int argc, const char *argv[])
{
//	while(1);
	
	sleep(5);

	//杀死自己
	//kill(getpid(), SIGKILL);
	
	raise(SIGKILL);

	//杀死父进程
	//kill(getppid(), SIGKILL);

	printf("---------------\n");
	
	return 0;
}
