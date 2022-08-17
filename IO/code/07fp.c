#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE *fp = fopen("./a.txt", "w+");	
	if(NULL == fp)
	{
		perror("fopen");
		return -1;
	}

	fputc('x', fp); //必须要用一次fp, 它才开辟缓存区

	printf("size=%d\n", fp->_IO_buf_end - fp->_IO_buf_base);

	int i;
	for(i=0; i<4096; i++)
	{
		fputc('x', fp);
	}

	while(1);
//  fflush(fp);	
//  return 0;
//  exit(0);
//	fclose(fp);

	return 0;
}
