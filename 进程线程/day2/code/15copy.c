#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	if(argc!=3)
	{
		printf("%s src_file dest_file\n", argv[0]);
		return -1;
	}

	int fd1 = open( argv[1] , O_RDONLY);
	if(fd1 < 0)
	{
		perror("open");
		return -1;
	}

	int fd2 = open( argv[2] , O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if(fd2 < 0)
	{
		perror("open");
		return -1;
	}

	printf("fd1=%d fd2=%d\n", fd1, fd2);

	char buf[100] = {0};

	while(1)
	{
		int n = read(fd1, buf, sizeof(buf));
		if(n< 0)
		{
			perror("read");
			return -1;
		}
		else if(n == 0) //读到文件的末尾了
		{
			break;
		}

		write(fd2, buf, n);

		memset(buf, 0 ,sizeof(buf));
	}

	printf("copy success!\n");

	close(fd1);
	close(fd2);

	return 0;
}
