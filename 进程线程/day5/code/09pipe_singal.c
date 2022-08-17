#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd[2];

	pipe(fd);

	close(fd[0]);

	write(fd[1], "xx", 2);

	printf("-------------\n");

	return 0;
}
