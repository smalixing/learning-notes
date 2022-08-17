**分享**



**复习{**



exec函数族：在一个进程中启动另一个进程



自己重生

fork，子进程重生



execl

execv

execlp

execvp

execle

execve



守护进程：

1.fork   结束父进程

2.setsid(); 创建新的会话

3.chdir(); 改变工作目录

4.umask(); //增加安全性

5.close(0);close(1);close(2); //关闭文件描述符



线程：轻量级的进程，同一个地址空间中的多个任务

pthread_t tid; 

pthread_create(&tid, NULL, fun, NULL);

pthread_detach(tid);



pthread_exit(void *retval); //return

pthread_join(  tid,   void **retval);



pthread_cancel();



优点：任务切换效率高，全局变量是共享的

缺点：竟态（多个任务同时访问共享资源）



同步： 1  2  1  2  1  2  1  2......

互斥：不呢同时访问



信号量：

sem_t sem;

sem_init(&sem, 0, 0);

sem_wait(&sem); //-1

sem_post(&sem);// +1



互斥锁:

pthread_mutex_t mutex;

pthread_mutex_init(&mutex, NULL);

pthread_mutex_lock(&mutex);

pthread_mutex_unlock(&mutex);



**}**





***作业1： myshell.c (自己实现 bash 的效果)***





下面是 strtok() 函数的声明。

```
char *strtok(char *str, const char *delim)
```

参数

- **str** -- 要被分解成一组小字符串的字符串。
- **delim** -- 包含分隔符的 C 字符串。

返回值：该函数返回被分解的第一个子字符串，如果没有可检索的字符串，则返回一个空指针。

实例：

下面的实例演示了 strtok() 函数的用法。



```c
#include <string.h> 
#include <stdio.h>  
int main () 
{   
  char str[80] = "This is - www.runoob.com - website";   
  const char s[2] = "-";   
  
  char *token;      /* 获取第一个子字符串 */   
  
  token = strtok(str, s);  /* 继续获取其他的子字符串 */   
  while( token != NULL )
  {      
    printf( "%s\n", token );          
    token = strtok(NULL, s);   
  }      
  return(0); 
}
```







***作业2： 完成文件拷贝（用线程来做）***





















**【1】传统的进程间通信**



无名管道

有名管道

信号







原始的方式：用文件中转











**1.无名管道 （pipe）**

查看命令： man 2 pipe

```c
头文件：#include <unistd.h>

函数原型： int pipe(int pipefd[2]);

pipefd[2] ：无名管道的两个文件描述符，int型的数组，大小为2，pipefd[0]为读端，pipefd[1]为写端

返回值：
	成功：0
	失败：-1
```

无名管道的特点：
a、没有名字，因此无法使用open()打开
b、只能用于亲缘进程间（如父子进程、兄弟进程、祖孙进程等）通信
c、半双工工作方式，读写端是分开的，pipefd[0]为读端，pipefd[1]为写端
d、是一种特殊的文件，只存在内存中，由内核进行管理
e、对于它的读写可以使用文件IO如read、write函数
f、无名管道的操作属于一次性操作，如果对无名管道进行读操作，数据会被全部读走



```c
单工：固定一种方向进行通信  广播

半双工：同一时间只能由一端发送到另一端  对讲机

全双工：通信方向都可以，同时可以发送也可以接收  电话
```



既然说是管道，所以可以想象成一条水管，连接两个进程，
一个进程负责输入数据，另一个进程负责接收数据，反过来也一样。

所以在无名管道中也一样，无名管道的两端，每一端都可以读和写。



**示例1：一个进程**

<img src="D:/WORK/1.record/01 应用层/04 IO-进线程/班级/220303/笔记/进线程/无名管道-一个进程读写机制.png" style="zoom: 67%;" />











**示例2：两个亲缘进程**
若一端为读就要关闭他的写功能，另一端就只能为写关闭读功能。

<img src="D:/WORK/1.record/01 应用层/04 IO-进线程/班级/220303/笔记/进线程/无名管道-两个进程的读写机制.png" style="zoom:67%;" />



注意事项：

1. 当管道中无数据时，执行读操作，读操作阻塞

  2. 无名管道的大小是固定的，管道一旦满，写操作就会导致进程阻塞
  3. 对无名管道的操作，类似一个队列，后写入的数据不会覆盖之前的数据，会在其后面存储，读取完的数据会从管道里面移除
  4. 将读端关闭，向无名管道中写数据，管道破裂，进程收到信号（SIGPIPE）,默认这个信号会将进程杀死 
  5. 当管道中有数据，将写端关闭，读操作可以执行，之后数据读完，可以继续读取（非阻塞），直接返回0























**2.有名管道 (fifo)**

有名管道也叫命名管道，在文件系统目录中存在一个管道文件。

管道文件仅仅是文件系统中的标示，并不在磁盘上占据空间。在使用时，在内存上开辟空间，作为两个进程数据交互的通道。

```c
1、查看命令：man 3 mkfifo

2、头文件：
#include <sys/types.h>
#include <sys/stat.h>

3、函数原型：
int mkfifo(const char *pathname, mode_t mode);
功能： 创建有名管道
参数：
  pathname: 文件的路径名
  mode: 权限
  

在shell中使用mkfifo命令： mkfifo filename

eg:

mkfifo f1

or

if(mkfifo("fifo",0666) == -1)
{  
		perror("mkfifo ");
		return -1;
}
```

特点：

      	  1. 有名管道存在文件系统中，数据存在内存中
          2. 可以用于无亲缘关系的进程
          3. 只有读端和写端同时存在管道才能打开成功。 

数据传输特点：
		1、读端不存在时，写端写入数据将会阻塞
		2、读端意外结束，写端再写数据将会管道破裂，该进程结束
		3、有名管道的数据存储在内存中，数据交互在内核中











有名管道和无名管道的异同点
1、相同点
open打开管道文件以后，在内存中开辟了一块空间，管道的内容在内存中存放，有两个指针—-头指针（指向写的位置）和尾指针（指向读的位置）指向它。读写数据都是在给内存的操作，并且都是半双工通讯。
2、区别
有名在任意进程之间使用，无名在父子进程之间使用



















**3.信号** 

简单概念：信号是在软件层次上对中断机制的一种模拟

kill把信号发送给进程或进程组;

raise把信号发送给(进程)自身.

```c
#include <signal.h>

int kill(pid_t pid, int  signo);
int raise(int  signo);

成功则返回0, 出错则返回-1


raise(signo);   等价于  kill(getpid(), signo);
```



























alarm();//设置闹钟

```c
#include <unistd.h>

unsigned int alarm(unsigned int seconds);
```



可以为当前进程定义闹钟，时间到了会发出SIGALRM信号。
每个进程只能有一个alarm，当重新定义时，会重新计时。
如果之前定义了一个闹钟，则这次定义返回的是上次闹钟剩余的时间，否则返回0.



pause();//程序暂停

pause函数的作用，是让当前进程暂停运行，交出CPU给其他进程去执行；
当前进程进入pause状态后，当前进程会表现为“卡住、阻塞住”；
要退出pause状态，当前进程需要被信号唤醒。









```c
信号的三种处理方式：
1.忽略 2.默认 3.自定义信号处理函数

sighandler_t signal(int signum, sighandler_t handler);
//捕获信号，设置信号的处理方式
//handler: SIG_IGN:忽略
//         SIG_DFL:默认
//         自定义的信号处理函数
```

```c
SIGINT : ctrl + c 

SIGQUIT : ctrl +\

SIGTSTP : ctrl + z
```





















***作业:实现本地聊天软件（管道）***











