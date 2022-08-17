#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd = open("./1.txt", O_RDWR);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}

	//read write

	printf("open success!\n");

	close(fd);

	return 0;
}
