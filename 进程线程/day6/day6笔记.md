【1】进程间通信方式
	

```c
传统进程间通信方式：
					无名管道
					有名管道
					信号
	
system V的IPC对象：
					共享内存（share memory）
					消息队列（message queue）
					信号灯集
	
BSD: 套接字
```


ipcs	

```c
ipcs -m :查询显示当前系统的共享内存
ipcs -q  :查询显示当前系统的消息队列
ipcs -s   :查询显示当前系统的信号灯集

ipcrm -m shmid：删除某个共享内存
ipcrm -q msgid：删除某个消息队列
ipcrm -s semid：删除某个信号灯集
```


​		
​		
​		
【2】IPC步骤：

```c
	  key						    id
ftok ----> shm_get/msg_get/sem_get ----> 
										 shmmat/shmdt/shmctrl
										 msgctrl/msgsend/msgrecv
										 semctrl/semop
```





```c
#include <sys/types.h>
#include <sys/ipc.h>

key_t ftok(const char *pathname, int proj_id); 
功能：生成一个KEY值
参数：
  pathname: 路径名
  proj_id:  1-255
    
返回值：
  成功： key
  失败： -1
```











【3】共享内存share memory
	

是一种通信效率最高的进程间通信方式，
	
进程间通信时直接访问内存，不需要进行数据的拷贝。



```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

步骤：

 	1. ftok
 	2. shmget
 	3. shmat
 	4. 进程间通信 fork
 	5. shmdt
 	6. shmctl
  

int shmget(key_t key, size_t size, int shmflg);
功能：创建共享内存
参数：
  key: ftok函数的返回值  or  IPC_PRIVATE  
  size: 内存大小  1024bytes 4096bytes
  shmflg:
			IPC_CREAT|0666
返回值：  
  成功：shmid
  失败：-1
        
void *shmat(int shmid, const void *shmaddr, int shmflg);
功能：映射    
参数： 
  shmid: shmget的返回值
  shmaddr: NULL 自动完成映射
  shmflg:
			SHM_RDONLY：只读
      0 ：读写  
返回值：
  成功：内存地址
  失败：NULL
 
          
          
int shmdt(const void *shmaddr);          
功能：解除映射
参数：
  shmaddr: shmat函数的返回值
返回值：
   成功：0 
   失败：-1
 
    
int shmctl(int shmid, int cmd, struct shmid_ds
       *buf);    
功能： 控制函数   
参数：    
    shmid: shmget函数的返回值 
    cmd: IPC_RMID 删除共享内存
    buf: NULL  
返回值：
   成功：0
   失败：-1   
```











【4】消息队列

```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

步骤：
	1. ftok
	2. msgget
	3. 进程间通信
	4. msgsnd
	5. msgrcv
	6. msgctl
  
int msgget(key_t key, int msgflg);
功能：创建消息队列
  
参数：
  key: ftok函数的返回值  or  IPC_PRIVATE
  msgflg: IPC_CREAT|0666
返回值:  
  成功：msgid
  失败：-1

    
		struct msgbuf {
      long mtype;       /* message type, must be > 0 */
      char mtext[N];    /* message data */
    };

 struct msgbuf msg;

int msgsnd(int msgid, const void *msgp, size_t msgsz, int msgflg);    
功能：发送数据  
参数：
  msgid: msgget函数的返回值
  msgp:  &msg
  msgsz: 发送正文的长度
    	sizeof(msg) - sizeof(long)
  msgflg:
		IPC_NOWAIT:非阻塞
    0：阻塞  
返回值：
    成功：0
    失败：-1
 
      
 struct msgbuf msg;
ssize_t msgrcv(int msgid, void *msgp, size_t msgsz, long msgtyp,int msgflg);
功能：接收数据       
参数：
  msgid:  msgget函数的返回值
  msgp: &msg
  msgsz:发送正文的长度
    sizeof(msg) - sizeof(long) 
  msgtyp: 消息的类型
  msgflg:
		IPC_NOWAIT:非阻塞
    0：阻塞			 
返回值：        
     成功：接收消息的长度   
     失败：-1   

        
        
int msgctl(int msgid, int cmd, struct msqid_ds *buf);        
功能： 删除消息队列      
参数：
  msgid:  msgget函数的返回值
  cmd: IPC_RMID
  buf: NULL
返回值：        
   成功；0 
   失败：-1 
    
```







【5】信号灯集

```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

步骤：
	1. ftok
	2. shmget
	3. shmat

*	4. semget
*	5. semctl
  6. 进程间通信
*	7. semop
*	8. semctl
  9. shmdt
  10. shmctl
  

int semget(key_t key, int nsems, int semflg);
功能：创建信号灯集  
参数：  
  key:ftok的返回值 or IPC_PRIVATE
  nsems: 设置的信号灯的数目
	semflg: 
  	IPC_CREAT|0666
返回值：
     成功：semid
     失败：-1
  
      
union semun {
      int val;  /* Value for SETVAL */
      struct semid_ds *buf;  
      unsigned short  *array;
      struct seminfo  *__buf; 
};
      
int semctl(int semid, int semnum, int cmd, ...);   功能：信号灯集控制函数   
参数：
   semid: semget的返回值
   semnum: 要设置的信号灯的编号  
   cmd：    
      IPC_RMID: 删除信号灯集
      SETVAL: 设置信号灯
   ...: 共用体的变量 or 不写     
返回值：
     成功：0
     失败：-1
 
     
     编号				初值
     0 	 sem0  	0     
     1 	 sem1  	1   

     子进程:写入
       sem1:-1  
       //write       
       sem0:+1  
		 父进程：读取 
       sem0:-1
       //read  
       sem1:+1  
       
int semop(int semid, struct sembuf *sops, unsigned nsops);     
功能：对信号灯进行PV操作  -1  +1     
参数：
  semid: semget的返回值
	sops: 结构体的变量的地址
    struct sembuf{
    	unsigned short sem_num;  /* semaphore number 信号灯的编号  */
			short sem_op;   /* semaphore operation 信号灯操作-1 +1*/
			short sem_flg;  /* operation flags 0：阻塞 */
    }
	nsops: 信号灯的个数 默认就是1
返回值：
    成功：0
    失败：-1
    
    
    
```

