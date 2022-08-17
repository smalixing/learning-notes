**分享**



**复习{**



进程：进行中的程序

进程号：唯一标识一个进程PID



R

S

D

T

Z



+

l

s



ps -ajx



ctrl+z 

jobs -l

bg %  作业号

fg % 作业号

top





pid_t pid = fork();

if(pid < 0 )   

{

​	perror("fork");

​	exit(-1);  //return -1;

}

else if(pid == 0) //子进程

{



}

else{ //父进程



}



exit(0);  //C库  有缓存

_exit(0); //系统调用函数  无缓存 



wait/waitpid





**}**



**作业：ls -l** 











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









































**【1】线程的概念**

1. 每个用户进程有自己的虚拟地址空间
2. 系统为每个用户进程创建一个
   task_struct 来描述该进程 struct task_struct 
3. task_struct 和地址空间映射表一起用来表示一个进程
4. 由于进程的虚拟地址空间是私有的，因此进程切换开销很大
5. 为了提高系统的性能，linux引入轻量级进程, 起名为线程
6. 在同一个进程中创建的线程共享该进程的地址空间
7. Linux里同样用task_struct来描述一个线程。

线程和进程都参与统一的调度

总结:

1. 通常线程指的是共享相同虚拟地址空间的多个任务
2. 使用多线程, 大大提高了任务切换的效率


线程不需要虚拟内存，为什么？

每个进程中至少有一个线程，就是主线程，还可以产生多个线程

共享4G内存空间，线程切换只需要虚拟CPU（寄存器）

同样用task_struct来描述一个线程，线程和进程都参于统一的调度

进程代表资源分配的最小单位
线程是最小的调度单位













线程概念：同一个地址空间中的多个任务







**【2】线程相关的函数**



创建线程

```c
#include <pthread.h>

pthread_t tid;  //线程号

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
功能：创建线程

参数：
  	thread: &tid  线程号的地址
		attr: NULL  默认参数（缺省参数） 线程的属性
    start_routine:  线程函数的函数名   
    arg: 给线程函数传递的参数 如果不传参 写NULL

返回值：
	成功： 0
	失败： 错误码
      
Compile and link with -pthread.
```





回收线程资源

```c
int pthread_join(pthread_t thread, void **retval);
功能：主线程等待子线程结束，回收它的资源（阻塞）
  
参数：
  thread: 线程号
  retval: 子线程的返回值
返回值：
	成功：0
  失败：-1

  
int pthread_detach(pthread_t thread);  
功能：主线程和子线程分离开来，自动回收资源 （非阻塞）
  
参数：
  	thread: 线程号
  
返回值：
	成功：0
  失败：-1  


```






结束子线程

```c
void pthread_exit(void *retval);
功能：结束子线程
参数：
  retval ： void *
返回值：
	成功：0
	失败：-1
```



线程传参{

​	值传递

​	地址传递

}







关闭线程

```c
int pthread_cancel(pthread_t thread);
```























优点：线程间很容易进行通信
   通过全局变量实现数据共享和交换

缺点：多个线程同时访问共享对象
　　　　时需要引入同步和互斥机制


同步和互斥 ：保护共享资源，避免竟态

同步：多个任务按理想的顺序/步调来进行
互斥：不能同时访问

都是为了避免竟态：多个任务同时访问共享资源











**【3】线程的同步------信号量**

```c
#include <semaphore.h>

sem_t sem; //信号量的变量

int sem_init(sem_t *sem, int pshared, unsigned int value);
功能：初始化信号量
参数：
  sem: &sem  信号量的变量的地址
	pshared: 0 :线程   1 ：进程
  value: 信号量的初值
返回值:
	成功：0
  失败：-1

int sem_wait(sem_t *sem);  //-1
//如果初值为0，会阻塞

int sem_post(sem_t *sem);  //+1
```

**//示例：主线程等待子线程结束**

**//练习： 计算键盘输入字符串的个数**

buf: 全局变量

主线程：输入字符串

子线程：打印字符串的长度









**【4】线程的互斥------互斥锁**

```c
pthread_mutex_t mutex; //互斥锁的变量

int pthread_mutex_init(pthread_mutex_t   *mutex, const pthread_mutexattr_t *mutexattr);
功能：初始化互斥锁
参数：
  	mutex: &mutex
		mutexattr: NULL (默认属性)
返回值：
    成功：0
    失败：-1
      
int pthread_mutex_lock(pthread_mutex_t *mutex);
//加锁

int pthread_mutex_unlock(pthread_mutex_t *mutex);
//解锁



```









***作业1： myshell.c (自己实现 bash 的效果)***

​	strtok();



***作业2：copy.c (用多线程进行读写操作)*** 

​	同步和互斥都可以



