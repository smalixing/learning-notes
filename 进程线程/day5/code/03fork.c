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
		exit(-1);
	}
	else if(pid == 0)
	{
		//写数据	
		int fd = open("./test.txt", O_WRONLY|O_CREAT|O_TRUNC,0666);

		write(fd, "hello\n", 7);

		close(fd);
	}
	else{

		sleep(1);

		//读数据
		int fd = open("./test.txt", O_RDONLY);
	
		char buf[100] = {0};

		read(fd, buf, sizeof(buf));

		printf("%s\n", buf);

		close(fd);
	}

	return 0;
}
