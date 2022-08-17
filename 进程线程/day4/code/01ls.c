#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <dirent.h>
#include <grp.h>

int main(int argc, const char *argv[])
{

	if(argc!=2)
	{
		printf("%s 目录名\n", argv[0]);
		return -1;
	}


	DIR *dirp = opendir(argv[1]);
	if(dirp == NULL)
	{
		perror("opendir");
		return -1;
	}

	chdir(argv[1]); // 改变工作目录

	while(1)
	{

		struct dirent *p = readdir(dirp);
		if( p == NULL )
		{
			break;
		}

		if( strncmp(p->d_name, ".", 1) == 0 )
		{
			continue;
		}

		struct stat mybuf;

		stat( p->d_name , &mybuf);

		//文件类型
		if(S_ISREG(mybuf.st_mode))
		{
			printf("-");
		}
		else if(S_ISCHR(mybuf.st_mode))
		{
			printf("c");
			//主设备号 次设备号
			//printf("%d %d\n", major(mybuf.st_rdev),
			//				minor(mybuf.st_rdev)
			//		);
		}
		else if(S_ISDIR(mybuf.st_mode))
		{
			printf("d");
		}
		else if(S_ISBLK(mybuf.st_mode))
		{
			printf("b");
		}
		else if(S_ISFIFO(mybuf.st_mode))
		{
			printf("p");
		}
		else if(S_ISSOCK(mybuf.st_mode))
		{
			printf("s");
		}
		else if(S_ISLNK(mybuf.st_mode))
		{
			printf("l");
		}



		//文件权限
		printf("%c", (mybuf.st_mode & (0x1<<8) )?'r':'-');
		printf("%c", (mybuf.st_mode & (0x1<<7) )?'w':'-');
		printf("%c", (mybuf.st_mode & (0x1<<6) )?'x':'-');
		printf("%c", (mybuf.st_mode & (0x1<<5) )?'r':'-');
		printf("%c", (mybuf.st_mode & (0x1<<4) )?'w':'-');
		printf("%c", (mybuf.st_mode & (0x1<<3) )?'x':'-');
		printf("%c", (mybuf.st_mode & (0x1<<2) )?'r':'-');
		printf("%c", (mybuf.st_mode & (0x1<<1) )?'w':'-');
		printf("%c", (mybuf.st_mode & (0x1<<0) )?'x':'-');


		//链接数
		printf("   %d   ", mybuf.st_nlink);


		//用户名
		struct passwd *q = getpwuid(mybuf.st_uid);

		printf("%s  ", q->pw_name);


		//组名
		struct group *g = getgrgid(mybuf.st_gid); 

		printf("%s  ", g->gr_name);


		//文件大小
		printf("%ld  ", mybuf.st_size);

		//最后一次修改的时间
		struct tm *k = localtime(&mybuf.st_mtime);
		printf("%d月 %d %d:%d ", k->tm_mon+1,
				k->tm_mday,k->tm_hour,k->tm_min
			  );

		printf("%s\n", p->d_name);

	}

	return 0;
}
