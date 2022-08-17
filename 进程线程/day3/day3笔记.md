```c
复习{
内存地址：
  char buf[];  
  struct A a;  //&a
  
fread(内存地址,每一块的字节数, 块数, 流指针);
  
fwrite(内存地址,每一块的字节数, 块数, 流指针) 

[printf相关函数]

组装数据：
  fprintf(fp, "%d-%d*%f,%s?%c:%d\n", 1,2,1.2,"xxx",'h', 3);
  sprintf(buf, "%d-%d*%f,%s?%c:%d\n", 1,2,1.2,"xxx",'h', 3);

提取数据:  
  int a ,b;
	sscanf(buf, "%d-%d", &a, &b);
  fscanf(fp, "%d-%d", &a, &b);

[时间函数]  
	time_t t;  
  time(NULL/&t);
  
 	struct tm *p = localtime(&t);
  p->年 月 日 时 分 秒
    
  char *p = ctime(&t);  //返回值：日历字符串的地址  

【文件IO】
  
int fd = open("文件路径名", 打开方式O_RDONLY, 0666);

fd( 0 ~ 1023)
stdin:0
stdout:1
stderr:2
  
close(fd);
  
  
int n = read(fd, buf, sizeof(buf));
if(n<0) //报错
if(n == 0) //读到文件的末尾
if(n > 0) //实际读取到的字节数
  
  
write(fd, buf, strlen(buf));
  
  
lseek(fd, 100, SEEK_SET);
  
}
```











作业：加密图片













**【目录操作函数】**



opendir

```C
#include <sys/types.h>
#include <dirent.h>

DIR *opendir(const char *name);
功能：打开目录
参数：
  name:路径名
返回值：
   成功： DIR *
   失败： NULL
```



readdir

```C
struct dirent *readdir(DIR *dirp);
功能：读取目录的信息
参数：
  dirp: opendir函数的返回值
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

struct stat mybuf;

int stat(const char *path, struct stat *buf);
功能：查看文件信息
参数：
  path：文件的路径名
	buf: &mybuf

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





**作业1： 完成ls -l**





















## 6.库的制作

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
   $ ./a.out    (7200)

优点：a.out 运行后不需要库，可以直接运行
缺点：
	每个a.out都要包含库，体积较大, 浪费资源;   
	对程序更新，部署，发布带来麻烦;



3、动态库的制作和使用

1. 制作
	$ gcc  -fPIC  -c  xxx.c  -o  xxx.o  
	$ gcc  -shared  -o  libxxx.so    xxx.o    

动态库的命名规范：
	必须以lib开头，紧跟库的名字，跟扩展名 .so
	例如: libxxx.so 

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





















**【进程】**

1. 进程

   进程是一个程序的一次执行的过程

   每一个进程都分配一个虚拟的4G内存

   0-3G  ： 用户
   3G-4G ： 内核


2. 进程和程序的区别

   程序是静态的
   进程是动态的


3. 进程的内存管理

   正文段、用户数据段、系统数据段

4. 进程号PID

   唯一的标识一个进程


5. 进程的类型

   交互进程（ctrl+z / jobs -l / bg / fg  / kill -l /kill -9 PID /ps -ajx）

   ctrl+z : 让进程变成后台进程

   jobs -l: 查看后台的进程，叫做作业    16674：作业号
   
   bg % 作业号：使后台进程恢复到前台，不能被ctrl+c结束（关闭终端即可）
   
   fg  % 作业号：使后台进程恢复到前台，能被ctrl+c结束
   
   kill -l: 查看信号的种类
   
   kill -9 PID: 结束相应的进程
   
   ps -ajx： 查看进程的属性
   
   
   
   批处理进程（运维）
   
   守护进程（ 1 init ）



6. 进程的运行状态

ps -ajx

运行态R：此时进程或者正在进行，或者准备运行
内核调度程序到CPU上执行 running

等待态：此时进程需要满足一些条件，如果不满足就等待
	可中断S：如果进程收到信号会醒来 ctrl+c
	不可中断D：如果进程收到信号不会醒来

停止态T：此时进程被中止SIGSTOP

死亡态Z：已终止的进程、僵尸进程
但还在进程向量数组中占有一个task_struct结构
task_struct{
	pid_t pid;
	R;
	...
};

+ ```c
  < 高优先级
  ​	N 低优先级
  ​	L 有些页被锁进内存
  ​	s 会话组组长
  
  + 位于前台的进程组
    l 多线程，克隆线程
  ```

  


ctrl + alt + f1 - f6 : 打开字符终端

	用户名：farsight
	密码：1

为了多用户使用计算机

结束字符终端： alt + f7


top

top -p PID  : 动态查看进程状态

renice -5 PID : 改变进程的NI值（默认0）





7.进程相关的函数

 	fork/exit  
	创建进程、退出进程

​	wait/waitpid
​	回收进程资源



```c
#include <unistd.h>

pid_t pid; //进程号

pid_t fork(void);
功能：创建进程
参数：无
返回值：
	pid < 0 :创建进程失败
  pid == 0 : 子进程
  pid > 0 : 父进程  
```












从fork函数往下分为两个进程开始运行。
父进程和子进程执行顺序是随机的。



fork函数特性： 
1.子进程创建时，几乎拷贝了父进程全部内容，包括代码段、数据段、堆栈段、文件描述符、虚拟地址空间
2.同一个父进程创建的子进程都是属于同一个进程组 
pkill -9 -g PGID
3.进程是管理资源的最小单位





思考: 
		int main()
		{
			fork();
			fork();
		}
		会创建多少个进程，进程之间的关系是什么样的?







```c
#include <stdlib.h>
void exit(int status); //有缓存


//系统调用函数
#include <unistd.h>
void _exit(int status); //无缓存
```















```c
pid_t wait(int *status);
功能：父进程等待子进程结束，回收它的资源
参数：
	status: 一般写NULL

WEXITSTATUS(status)  获取子进程返回值  

WIFEXITED(status)  判断子进程是否正常结束
```












	子进程先与父进程退出---父进程未回收资源---子进程会变成僵尸进程
		危害：占用进程号、内存空间、PCB进程控制块等
		解决：wait / waitpid / 信号
		注意：任何进程结束都会变成僵尸进程，只是时间有长有短


	父进程先与子进程退出---子进程会变成孤儿进程---被init进程接管(收养)
	
	init进程：系统启动后运行的第一个用户空间进程,pid=1,会定期扫描系统，收养孤儿进程。
	
	注意：孤儿进程一般没什么危害










```c
pid_t waitpid(pid_t pid, int *status, int options);
功能：父进程自动回收子进程结束后的资源
参数：
  pid: -1   任意进程
  status: NULL
	options: 
				0 阻塞
				WNOHANG 非阻塞
          
eg: waitpid(-1, NULL, 0); == wait(NULL);







```









**exec函数簇**

1. 概念：

   函数族提供了一种在进程中启动另一个程序执行的方法。
   它可以根据指定的文件名或目录名找到可执行文件，并用它来取代原调用进程的数据段、代码段和堆栈段，在执行完之后，原调用进程的内容除了进程号外，其他全部被新程序的内容替换了。另外，这里的可执行文件既可以是二进制文件，也可以是Linux下任何可执行脚本文件。

   比如bash用到了exec函数来执行我们的可执行文件。

   

2. 在Linux中使用exec函数族主要有以下两种情况

当进程认为自己不能再为系统和用户做出任何贡献时，就可以调用任何exec 函数族让自己重生。

如果一个进程想执行另一个程序，那么它就可以调用fork函数新建一个进程，然后调用任何一个exec函数使子进程重生。	

3. 函数 

  ```c
  #include <unistd.h>
     int execl(const char *path, const char *arg, ...);
     int execv(const char *path, char *const argv[]);
     int execlp(const char *file, const char *arg, ...);
     int execvp(const char *file, char *const argv[]);
     int execle(const char *path, const char *arg, ..., char *const envp[]);
     int execve(const char *path, char *const argv[],   char *const envp[]);
  
  
  返回值: 	
  		成功不返回
  		失败返回 -1 更新 errno
  ```


​	

	注意：
	​		exec函数的参数表传递方式以函数名的第五位字母来区分:
	​	字母为"l"(list)的表示逐个列举的方式;
	​	
		字母为"v"(vertor)的表示将所有参数构造成指针数组传递;
	
	以p结尾的函数可以只给出文件名
	
	以"e"(enviromen)结尾的两个函数execle、execve就可以在
	envp[]中设置当前进程所使用的环境变量
	使用execle和execve可以自己向执行进程传递环境变量，但不会继承Shell进程的环境变量



事实上，这6个函数中真正的系统调用只有execve，其他5个都是库函数，它们最终都会调用execve这个系统调用







**[守护进程daemon]**

1.守护进程：
	在linux中与用户交互的界面叫终端，从终端运行起来的程序都依附于这个终端，
	当终端关关闭时，相应的进程都会被关闭，守护进程可以突破这个限制。

2.特点：
	在后台服务的进程
	生存期很长
	守护进程独立于控制终端
	比如：init进程 pid=1 开机运行 关机才结束

3.守护进程创建流程：
	1. 创建子进程，父进程退出
		fork(void);
	2. 在子进程中创建新会话
		setsid(void);
	3. 修改工作目录
		chdir("");
	4. 修改umask (增加安全性)
		umask(); 
	5. 关闭文件描述(回收资源)
		close();
		
		
		











***作业1： myshell.c (自己实现 bash 的效果)***













