#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	fputc('x', stderr);

	while(1);

	return 0;
}
