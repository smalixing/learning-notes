#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd = open("./6.txt", O_CREAT|O_RDWR, 0666);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}

	printf("fd=%d\n", fd);

	printf("open success!\n");

	char buf[100] = {0};
		
	while(1)
	{
		gets(buf);
	
		int n = write(fd, buf, strlen(buf));
	
		printf("n=%d\n", n);
	}


	close(fd);

	return 0;
}
