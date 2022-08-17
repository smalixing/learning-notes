#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd[2];

	pipe(fd);

	char ch = 'x';

	int i;
	for(i=0; i<1024*64 ; i++)
	{
		write(fd[1], &ch, 1);
	}

	printf("111111111111\n");

	write(fd[1], &ch, 1);

	printf("222222222222222\n");

	return 0;
}
