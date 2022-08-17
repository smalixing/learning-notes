#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd[2];

	pipe(fd);

	write(fd[1], "hello", 5);

	close(fd[1]);

	char buf[100] ={0};

	int n1 = read(fd[0], buf, 5);

	printf("-------n1 = %d------\n", n1);

	int n2 = read(fd[0], buf, 5);

	printf("-------n2 = %d------\n", n2);

	return 0;
}
