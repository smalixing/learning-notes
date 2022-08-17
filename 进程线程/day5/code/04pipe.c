#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd[2];

	int ret = pipe(fd);
	if(ret == -1)
	{
		perror("pipe");
		return -1;
	}

	write(fd[1], "hello world", 12);

	char buf[100] = {0};

	int n = read(fd[0], buf, sizeof(buf));

	printf("n=%d\nbuf=%s\n", n, buf);

	return 0;
}
