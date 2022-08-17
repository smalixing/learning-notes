#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	alarm(5);

	sleep(2);

//	pause();

	int ret = alarm(5);

	printf("ret=%d\n", ret);

	while(1);

	return 0;
}
