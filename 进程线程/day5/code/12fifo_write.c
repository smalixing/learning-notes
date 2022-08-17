#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{

	//写
	int fd = open("./f1", O_WRONLY);

	char buf[100] = {0};

	while(1)
	{
		gets(buf);

		write(fd, buf, strlen(buf));
	}

	return 0;
}
