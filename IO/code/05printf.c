#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	
//	printf("hello world\n");
	printf("hello world");

	//缓存区的大小：1024Bytes
	//printf("size=%d", stdout->_IO_buf_end - stdout->_IO_buf_base );

	int i;

	for(i=0; i<1014; i++)
	{
		fputc('a', stdout);
	}

//	fflush(stdout);  //强制刷新标准输出流

//	fclose(stdout);  //关闭标准输出流

//	return 0;

//	exit(0);

	while(1);

	return 0;
}
