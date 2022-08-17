#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	char buf[1024] = {0};


	sprintf(buf, "%d-%d-%d %d:%d:%d %f    %s%c", 2022,7,21,
			11,28,30, 3.14, "hello", 'a');


	printf("%s\n", buf);

	return 0;
}
