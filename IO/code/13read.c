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

	printf("fd=%d\n", fd);

	printf("open success!\n");

	char buf[100] = {0};
	
	int count = 0;

	while(1)
	{
		int n = read(fd, buf, sizeof(buf));
		if(n< 0)
		{
			perror("read");
			return -1;
		}
		else if(n == 0) //读到文件的末尾了
		{
			break;
		}
	
		count += n;

		printf("n=%d\n", n);

		printf("buf:%s\n", buf);

		memset(buf, 0 ,sizeof(buf));
	}

	printf("count=%d\n", count);

	close(fd);

	return 0;
}
