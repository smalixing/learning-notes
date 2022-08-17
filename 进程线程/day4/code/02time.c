#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	while(1)
	{
		time_t t;
		time(&t);

		char *p = ctime(&t);

		printf("%s\n", p);

		sleep(1);
	}

	return 0;
}
