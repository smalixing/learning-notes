#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	fork();

	fork();

	fork();

	while(1);

	return 0;
}
