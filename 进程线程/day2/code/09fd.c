#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	
	printf("%d\n", stdin->_fileno);
	printf("%d\n", stdout->_fileno);
	printf("%d\n", stderr->_fileno);


	return 0;
}
