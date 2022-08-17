#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd[2];
	pipe(fd);

	printf("1111111111\n");
	
//	write(fd[1], "hello", 6);

	char buf[100] ={0};

	read(fd[0], buf, sizeof(buf));

	printf("buf=%s\n", buf);

	printf("2222222222222\n");

	return 0;
}
