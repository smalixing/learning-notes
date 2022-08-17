inc	头文件

src	源码

客户端功能：

​	1、发送请求：上传下载查询

​	2、接收内容、解析指令

​	3、接收完成后发送成功指令

服务器功能：

​	1、解析请求并执行操作

​	2、先发大小再发内容、结束后发送完毕指令

​	3、接收成功指令

![image-20220805140354383](C:\Users\smallxing\AppData\Roaming\Typora\typora-user-images\image-20220805140354383.png)

```c
指令(客户端服务器通信)
ls	#define L 100
get 		G 101
PUT         P 102
success		Y 103
发送失败	  N 104
    		E 105
struct data{
    char cmd;//执行指令
    int len;//文件长度
    char buf[100];//文件信息
}From;
#define FSIZE sizeof(From)
```

types.h

```c
#ifndef __TYPES_H__
#define __TYPES_H__

typedef struct data{
    char cmd;//执行指令
    int len;//文件长度
    char buf[100];//文件信息
}From;

#define FSIZE sizeof(From)
#define L 101
#define G 102
#define P 103
#define Y 104
#define N 105
#define E 106
//网络相关
#define IP "0.0.0.0"
#define PORT 8888
#define BK 1024

#endif
```

tftp.h

```c
#ifndef __TFTP_H__
#define __TFTP_H__
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//获取当前目录下的文件名，打包发送给客户端
int List_filename(int fd);
//从服务器下载文件
int Get_file(int fd, From from);
//从客户端上传文件
int Put_file(int fd, From from);
#endif
```

tftp.c

```c
#include "types.h"
#include "tftp.h"

//获取当前目录下的文件名，打包发送给客户端
int List_filename(int fd){}
//从服务器下载文件
int Get_file(int fd, From from){}
//从客户端上传文件
int Put_file(int fd, From from){}
```

main.c

```
#include "ser.h"
#include "tftp.h"
#include "types.h"

int main()
{
	From from;
	int fd = server_init()
	if(ret == -1)
}
```

![image-20220805142634430](C:\Users\smallxing\AppData\Roaming\Typora\typora-user-images\image-20220805142634430.png)

![image-20220805143318795](C:\Users\smallxing\AppData\Roaming\Typora\typora-user-images\image-20220805143318795.png)