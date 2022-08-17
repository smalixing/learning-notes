#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE *fp = fdopen(1, "w");

	fprintf(fp, "%d-%d-%d\n", 2022,7,21);

	return 0;
}
