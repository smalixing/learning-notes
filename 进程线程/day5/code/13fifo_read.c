#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	//读
	int fd = open("./f1", O_RDONLY);

	char buf[100] = {0};

	while(1)
	{
		read(fd, buf, sizeof(buf));

		printf("buf = %s\n", buf);

		memset(buf, 0, 100);
	}

	return 0;
}
