#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE *fp = fopen("./2.txt", "r+");
	if(NULL == fp)
	{
		perror("fopen");
		return -1;
	}

	printf("%d\n", fgetc(fp));
	printf("%c\n", fgetc(fp));
	printf("%c\n", fgetc(fp));
	printf("%c\n", fgetc(fp));
	printf("%c\n", fgetc(fp));


	fputc(121, fp);
	fputc(121, fp);
	fputc(121, fp);
	fputc(121, fp);
	fputc(121, fp);
	fputc(121, fp);
	
	fclose(fp);

	return 0;
}
