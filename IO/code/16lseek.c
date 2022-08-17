#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd = open("./test.txt", O_CREAT|O_RDWR, 0666);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}

	printf("fd=%d\n", fd);

	printf("open success!\n");


	write(fd, "hello", 5);


	lseek(fd, 100, SEEK_END);


	write(fd, "world", 5);


	close(fd);

	return 0;
}
