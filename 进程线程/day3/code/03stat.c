#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	if(argc!=2)
	{
		printf("%s 文件路径名\n", argv[0]);
		return -1;
	}

	struct stat mybuf;

	stat(argv[1], &mybuf);

	//文件类型
	if(S_ISREG(mybuf.st_mode))
	{
		printf("-\n");
	}
	else if(S_ISCHR(mybuf.st_mode))
	{
		printf("c\n");
		//主设备号 次设备号
		printf("%d %d\n", major(mybuf.st_rdev),
						minor(mybuf.st_rdev)
				);
	}


	//文件权限
	printf("%c", (mybuf.st_mode & (0x1<<8) )?'r':'-');
	printf("%c", (mybuf.st_mode & (0x1<<7) )?'w':'-');
	printf("%c", (mybuf.st_mode & (0x1<<6) )?'x':'-');

	printf("\n");


	//链接数
	printf("%d\n", mybuf.st_nlink);


	//用户名
	struct passwd *p = getpwuid(mybuf.st_uid);

	printf("%s\n", p->pw_name);

	//文件大小
	printf("%ld\n", mybuf.st_size);

	//最后一次修改的时间

	struct tm *k = localtime(&mybuf.st_mtime);
	printf("%d月\n", k->tm_mon+1);



	return 0;
}
