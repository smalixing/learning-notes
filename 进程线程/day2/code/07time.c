#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	time_t t;

	while(1)
	{
		int m = time(&t);
		
		printf("秒数:%d\n", m);
	
		sleep(1);
	}

	return 0;
}
