#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	if(argc!=2)
	{
		printf("%s picture\n", argv[0]);
		return -1;
	}

	int fd = open(argv[1], O_RDWR);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}

	char buf[10] ={0};

	read(fd, buf, 10);

	int i;
	for(i=0; i<5; i++)
	{
		buf[i] ^= buf[9-i];  
		buf[9-i] ^= buf[i];  
		buf[i] ^= buf[9-i];  	
	}

	lseek(fd, 0 , SEEK_SET);

	write(fd, buf, 10);


	printf("加密解密成功!\n");

	close(fd);

	return 0;
}
