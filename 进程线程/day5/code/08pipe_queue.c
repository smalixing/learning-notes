#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd[2];
	pipe(fd);

	write(fd[1], "xxx", 3);

	write(fd[1], "yyy", 3);

	write(fd[1], "hello", 5);

	char buf[100] = {0};

	read(fd[0], buf, 4);

	printf("1 = %s\n", buf);

	memset(buf, 0, 100);

	read(fd[0], buf, 4);

	printf("2 = %s\n", buf);

	memset(buf, 0, 100);

	return 0;
}
