#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, const char *argv[])
{
	if(argc!=2)
	{
		printf("%s 目录名\n", argv[0]);
		return -1;
	}

	DIR *dirp = opendir(argv[1]);
	if(dirp == NULL)
	{
		perror("opendir");
		return -1;
	}

	while(1)
	{
		struct dirent *p = readdir(dirp);
		if( p == NULL )
		{
			break;
		}

		if( strncmp(p->d_name, ".", 1) == 0 )
		{
			continue;
		}

		printf("%s ", p->d_name);
	}

	puts("");  //printf("\n");  putchar('\n');

	closedir(dirp);

	return 0;
}
