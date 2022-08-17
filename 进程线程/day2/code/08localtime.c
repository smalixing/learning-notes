#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	FILE *fp = fopen("./time.txt", "a");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}

	while(1)
	{

		time_t t;

		time(&t);

		struct tm *p = localtime(&t);

		printf("%d-%d-%d %d:%d:%d\n", p->tm_year+1900,
				p->tm_mon+1,p->tm_mday,
				p->tm_hour,p->tm_min,p->tm_sec
			  );

		fprintf(fp, "%d-%d-%d %d:%d:%d\n", p->tm_year+1900,
				p->tm_mon+1,p->tm_mday,
				p->tm_hour,p->tm_min,p->tm_sec
			  );

		fflush(fp);

		sleep(1);
	}

	fclose(fp);

	return 0;
}
