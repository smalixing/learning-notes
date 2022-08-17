#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork");
		return -1;
	}
	else if(pid == 0)
	{
		//写
		int fd = open("./f1", O_WRONLY);

		char buf[100] = {0};

		while(1)
		{
			gets(buf);
		
			write(fd, buf, strlen(buf));
		}
	
	}
	else{
	
		//读
		int fd = open("./f1", O_RDONLY);
		
		char buf[100] = {0};

		while(1)
		{
			read(fd, buf, sizeof(buf));
			
			printf("buf = %s\n", buf);

			memset(buf, 0, 100);
		}
	
	}

	return 0;
}
