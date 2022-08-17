分享录视频就行



```c
复习{

文件：一切皆文件
文件类型：
  常规文件
  目录
  字符设备
  块设备
  管道
  链接
  套接字
  
文件IO和标椎IO的区别

标准IO：
	FILE *fp = fopen("./1.txt", "r/r+/w/w+/a/a+");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}
  
  //freopen("./1.txt", "w", stdout);
  
  //fgetc(fp); //获取一个字节的数据
	//fputc('x', fp); //写入一个字节的数据

  //fgets(buf, sizeof(buf), fp); //读取一行的数据
  //fputs("hello", fp); //写入一行的数据
  
  //fseek(fp,  100,  SEEK_SET/SEEK_END/SEEK_CUR);
  
  //int n = ftell(fp);  //计算文件大小n
  
  //rewind(fp); //文件指针移到开头
  
	fclose(fp);

  行缓存：	printf/stdin/stdout  1K    			
  1. '\n'  2. 缓存区满了  3. exit return  
  4. fflush(stdout);  5.fclose(stdout);
  
  无缓存： stderr
  
  全缓存： fopen打开的文件 fp->_IO_buf_end - fp->_IO_buf_base  4K
  1. 缓存区满了  2. exit return  3. fflush(fp);  4.fclose(fp); 
  
  
}
```







作业：查单词

流程：

  1.打开文件

2. 循环
3. 输入一个单词
4. 遍历文件 
5. 打印出单词信息
6. 重新开始查询
7. 关闭文件











标准IO： fopen/fclose/fgetc/fputc/fgets/fputs/fread/fwrite



FILE  *fp  ：流指针  （文本流、二进制流）



FILE *fp = fopen("./1.txt", "rb");

rb

rb+/r+b

wb

wb+/w+b

ab

ab+/a+b



```c
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
功能：读取数据
参数：
  ptr: 内存地址 
	size: 每块的字节数
  nmemb:  块数
	stream: 流指针
返回值：
    成功：块数
    失败：-1
```

```
char buf[1000] = {0};

fopen("./1.txt", "rb");

fread(buf, 100, 10, fp);
fread(buf, 1000, 1, fp);
fread(buf, 10, 100, fp);
fread(buf, 1, 1000, fp);
fread(buf, 50, 20, fp);
......
```





```c
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
功能：写入数据
参数：
  ptr: 内存地址
	size: 每块的字节数
  nmemb:  块数 
	stream: 流指针
返回值：
    成功：块数
    失败：-1
```







【练习：怪兽乐园】
typedef struct Monster{
	int ID;
	char name[50];
	char species[50];
	char type[50];
}MOS;









【printf相关函数】

**组装数据**

```c
int  fprintf(FILE  *stream,  const  char *format, ...);
功能：
参数：
  stream: 流指针
  format: 格式控制符
  ...：不定参数
```

fprintf(  fp,  "%d-%d-%d" , 2022,7,21);



```c
int sprintf(char *str, const char *format, ...);
功能：
参数：
  str: 内存地址
  format: 格式控制符
  ...：不定参数
```



**提取数据**

```c
int sscanf(const char *str, const char *format, ...);
功能：从内存中提取数据出来
参数：
  str: 内存地址
  format: 格式控制符
  ...：不定参数
```

```c
int fscanf(FILE *stream, const char *format, ...);
功能：从文件（流指针）中提取数据出来
参数：
  stream: 流指针
  format: 格式控制符
  ...：不定参数
```





**【时间函数】**

```c
#include <time.h>
#include <unistd.h>

time_t t;
time_t time(time_t *t);
功能：从1970-1-1 0:0:0开始到现在的秒数
参数：
	t:  &t / NULL
返回值：
    成功：从1970-1-1 0:0:0开始到现在的秒数
    失败：-1
```


```c
#include <time.h>

time_t t;
struct tm *localtime(const time_t *timep);
功能：从1970-1-1 0:0:0开始到现在的秒数转化成日历
参数：
	timep: &t
返回值：
    成功：struct tm *
    失败：NULL
```

```c
struct tm {
   int tm_sec;    /* Seconds (0-60) */
   int tm_min;    /* Minutes (0-59) */
   int tm_hour;   /* Hours (0-23) */
   int tm_mday;   /* Day of the month (1-31) */
   int tm_mon;    /* Month (0-11) */
   int tm_year;   /* Year - 1900 */
};
```



示例：获取系统时间

练习：获取系统时间，并将系统时间 打印并输出到 文件中
	[2020-05-07 14:07:30]
	[2020-05-07 14:07:31]
	[2020-05-07 14:07:32]





## 文件IO

**文件描述符**

文件描述符实际上是一个索引值，指向内核为每一个进程所维护的该进程打开文件的记录表。当程序打开一个现有文件或者创建一个新文件时，内核向进程返回一个文件描述符，进程使用它来标识打开的文件。在程序设计中，一些涉及底层的程序编写往往会围绕着文件描述符展开。但是文件描述符这一概念往往只适用于UNIX、Linux这样的操作系统。

Linux系统为程序中每个打开的文件都分配一个文件描述符，文件IO操作通过文件描述符来完成。

文件描述符在形式上是一个顺序分配的非负整数。从0开始分配，依次递增。比如 0，1，2表示 stdin stdout stderr，一般最大打开的文件描述符数量为1024（0~1023）



//打印文件描述符



fdopen

```c
FILE *fdopen(int fd, const char *mode);
功能：把文件IO转化成标准IO
参数；
  fd: 文件描述符
  mode: 打开方式
返回指：
    成功：FILE *
    失败：NULL
```









**【常用的文件IO函数】**

```c
//open/close/read/write/lseek
```





```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//打开文件，文件已存在
int open(const char *pathname, int flags);

//创建文件，文件不存在
int open(const char *pathname, int flags, mode_t mode);
参数：
  pathname: 文件的路径名 
	flags: 
		O_RDONLY:只读
    O_WRONLY:可写  
		O_RDWR: 读写
    O_CREAT :创建
    O_TRUNC :清空  
    O_APPEND:追加
      
  mode: 权限
返回指：    
    成功：文件描述符fd
    失败：-1
```


```c
标准IO 		文件IO
	r			O_RDONLY
	r+			O_RDWR
	w			O_WRONLY | O_CREAT | O_TRUNC
	w+			O_RDWR   | O_CREAT | O_TRUNC
	a			O_WRONLY | O_CREAT | O_APPEND
	a+			O_RDWR   | O_CREAT | O_APPEND
```











实际创建的文件权限需要经过一个公式计算得到： mode & (~umask)





```c
#include <unistd.h>

int close(int fd);
```







```c
ssize_t read(int fd, void *buf, size_t count);
功能：从文件中读取数据到内存
参数：
  fd: 文件描述符：open函数的返回值
  buf: 内存地址 char buf[];
	count: 读取的字节数
返回值：
    成功：返回实际读取到的字节数n
			   n == 0 取到文件末尾
				 n > 0  成功读取到的字节数
    失败：n<0	读取失败
     
```

统计文件的大小



```c
ssize_t  write(int  fd,  const void *buf, size_t count);
功能：把内存中的数据写入到文件中
参数：
  fd: 文件描述符
  buf: 内存地址
	count: 写入的字节数
返回值：
    成功：实际写入的字节数n
				n>=0
    失败：n<0
      
```





***open\close\read\write***



练习：copy.c







```c
off_t lseek(int fd, off_t offset, int whence);
功能：定位文件指针
参数：
  fd: 文件描述符
  offset: 偏移量
    100：向后偏移100个字节
    -100：向前偏移100个字节
  whence: 基点
    SEEK_SET:文件开头
    SEEK_END:文件末尾
    SEEK_CUR:文件当前位置
返回值：
    成功：0
    失败：-1
```

lseek(fd, 0, SEEK_END);







day2作业：使用文件IO的函数加密图片  （音频、视频）























**【目录操作函数】**



opendir

```C
#include <sys/types.h>
#include <dirent.h>

DIR *opendir(const char *name);
功能：
参数：
  name:
返回值：
   成功： DIR *
   失败： NULL
```



readdir

```C
struct dirent *readdir(DIR *dirp);
功能：
参数：
  dirp: 
返回值：
   成功： struct dirent *
   失败： NULL（一直遍历，直到遍历目录完成返回NULL）


struct dirent {
   ino_t          d_ino;       /* inode number */
   off_t          d_off;       /* not an offset; see NOTES */
   unsigned short d_reclen;    /* length of this record */
   unsigned char  d_type;      /* type of file; not supported
								  by all filesystem types */
   char           d_name[256]; /* filename */
};
```



closedir

```C
int closedir(DIR *dirp);
```



示例：查看目录下的文件







**【文件信息函数】**



stat

```C
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat buf;

int stat(const char *path, struct stat *buf);
功能：
参数：
  path：
	buf:

-rw-rw-r-- 1 farsight farsight   593  4月 19 09:26 01picture.c
-rw-rw-r-- 1 farsight farsight   537  4月 19 09:53 02readdir.c
-rw-rw-r-- 1 farsight farsight   161  4月 19 10:23 03stat.c
-rwxrw-rw- 1 farsight farsight 97893  4月 19 09:26 5.jfif
-rwxrwxr-x 1 farsight farsight  7357  4月 19 09:53 a.out
    
//查看设备号
major   minor
  
    
struct stat {
	dev_t     st_dev;     /* ID of device containing file */
	ino_t     st_ino;     /* inode number */
	mode_t    st_mode; 文件的权限、文件的类型   /* protection */
	nlink_t   st_nlink;   /* number of hard links */
	uid_t     st_uid;  所属用户ID   /* user ID of owner */ 
	gid_t     st_gid;  所属组ID   /* group ID of owner */
	dev_t     st_rdev;    /* device ID (if special file) */
	off_t     st_size; 文件的大小   /* total size, in bytes */
	blksize_t st_blksize; /* blocksize for filesystem I/O */
	blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
	time_t    st_atime; 最后一次访问时间  /* time of last access */
	time_t    st_mtime; 最后一次修改时间  /* time of last modification */
	time_t    st_ctime; 最后一次文件文件属性修改时间  /* time of last status change */
};
```



getpwuid

```C
struct passwd *getpwuid(uid_t uid);


struct passwd {
   char   *pw_name;       /* username */
   char   *pw_passwd;     /* user password */
   uid_t   pw_uid;        /* user ID */
   gid_t   pw_gid;        /* group ID */
   char   *pw_gecos;      /* user information */
   char   *pw_dir;        /* home directory */
   char   *pw_shell;      /* shell program */
};
```



getgrgid

```C
struct group *getgrgid(gid_t gid);

struct group {
	char   *gr_name;       /* group name */
	char   *gr_passwd;     /* group password */
	gid_t   gr_gid;        /* group ID */
	char  **gr_mem;        /* group members */
};
```



示例：stat.c

```C
文件类型
{
	常规文件：S_ISREG 	'-'
	目录：S_ISDIR 		'd'
	字符设备：S_ISCHR 	'c'
	块设备：S_ISBLK 	'b'
	管道：S_ISFIFO 		'p'
	套接字：S_ISSOCK 	's'
	符号链接：S_ISLNK 	'l'
}
```





***作业1：完成 ls -l***















## 库的制作

1、什么是库
	/lib/i386-linux-gnu
	/usr/include

1. 库是一种加密的二进制文件
2. 需要被操作系统载入内存运行
3. 相比于可执行程序，它不可以直接运行
4. window 和 linux 都有自己的库，但是不兼容
5. Linux系统的库有两种，1. 静态库  2. 共享库(又叫动态库)

```C
了解: 	静态库		动态库
linux	*.a			*.so

//window 	*.lib		*.dll
```


​	

2、静态库的制作和使用
	1. 制作
		$ gcc -c    xxx.c  -o  xxx.o
		$ ar  -crs  libxxx.a     xxx.o	

​	静态库的命名规范：
​	必须以lib开头，紧跟库的名字，跟扩展名 .a 
​	例如: libxxx.a

2. 使用
   $ gcc  main.c   -L路径  -lxxx
   -L: 指定静态库所在的目录
   -l: 指定静态库的名字   xxx部分

3. 运行
   $ ./a.out    (7258)

优点：a.out 运行后不需要库，可以直接运行
缺点：
	每个a.out都要包含库，体积较大, 浪费资源;   
	对程序更新，部署，发布带来麻烦;



3、动态库的制作和使用

```c
1. 制作
	$ gcc  -fPIC  -c  xxx.c  -o  xxx.o  
	$ gcc  -shared  -o  libxxx.so    xxx.o    
	
动态库的命名规范：
	必须以lib开头，紧跟库的名字，跟扩展名 .so
	例如: libxxx.so 
```

2. 使用
   $ gcc  main.c   -L路径  -lxxx

   

   

   $ ldd  a.out   # 用于查看可执行程序依赖的动态库有哪些

3. 运行
   $ ./a.out    # 会报错 （7146）

   动态库的搜索方式(3种，任意选一种):

   1. 将动态库拷贝到  /lib/ 或者 /usr/lib/
      $ sudo cp  libxxx.so   /usr/lib/

     2.export LD_LIBRARY_PATH=.或者so所在的路径 （临时情况）

   3. 

     pwd
     cd /etc/ld.so.conf.d
     ls
     sudo vi my.conf
     添加路径
     sudo ldconfig 生效 

特点：在编译时不会链接到可执行文件中，只是再其中保存一个索引，在运行时，才真正的链接(动态)，因此可执行程序体积小。
优点：
	a.out 体积较小, 节约资源;
	只需要修改.so动态库，有利于程序的更新，部署，发布;
缺点：a.out 运行后需要库，不能直接运行。






​	