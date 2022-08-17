TCP_Server：
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>

int socket(int domain, int type, int protocol);
返回值：> 0 代表函数调用成功，这个值是一个文件描述符
		< 0 代表函数调用失败
int domain：地址簇 AF_INET：IPv4 AF_INET6: IPv6 

int type: 套接字类型 SOCK_STREAM：流式套接字   唯一对应TCP 
		             SOCK_DGRAM:  数据报套接字 唯一对应UDP
					 SOCK_RAW:    原始套接字   针对较低层次协议

int protocol： 默认为0 
/*绑定通信IP和端口*/
struct sockaddr_in {
              sa_family_t sin_family; /* 地址族: AF_INET 2字节 */
              u_int16_t sin_port; /* 按网络字节次序的端口 2字节*/
              struct in_addr sin_addr; /* internet地址 */
              };

              /* Internet地址. */
              struct in_addr {
              u_int32_t s_addr; /* 按网络字节次序的地址 */
              };
struct sockaddr_in sddr;
bzero(&sddr, sizeof(sddr)); //将sddr做清0操作

uint16_t htons(uint16_t hostshort);
把本机字节序转为网络字节序
uint16_t ntohs(uint16_t netshort);
把网络字节序转为本机字节序

int bind(int sockfd, struct sockaddr *my_addr, socklen_t addrlen);
返回值：成功 0
        失败 -1
int sockfd: 				代表socket成功返回的文件描述符
struct sockaddr *my_addr ： 要绑定的IP和端口
socklen_t addrlen ：        要绑定的IP和端口的结构体的大小

int listen(int s, int backlog);
返回值：		成功 0
				失败 -1
int s:  		socket打开的文件描述符
int backlog :	允许监听的套接字队列元素的最大个数 （数目和性能产生联系）

int accept(int s, struct sockaddr *addr, socklen_t *addrlen);
返回值：				失败 -1
						成功 非负整数
int s: 					socket返回的文件描述 
struct sockaddr *addr： 存储连接进来的客户端的IP和端口 （NULL不关注客户端的信息）
socklen_t *addrlen：	结构体的大小

int atoi(const char *nptr)
返回值：			失败 -1
					成功 转化后的整型数据
const char *nptr：  要转化的目标字符串

int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
返回值：				成功 0
						失败 -1
int sockfd：    		socket返回的文件描述符
struct sockaddr *addr： 要连接的服务器的IP和PORT
socklen_t addrlen：		存储要连接服务器IP和PORT的结构体的长度
