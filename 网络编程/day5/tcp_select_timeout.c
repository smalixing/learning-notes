#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <unistd.h>


/* 定义服务器初始化函数 */
int server_init(char *ip, short port)
{
	int ret;
	int listenfd;
	struct sockaddr_in srvaddr;

	/* 创建套接字文件 */
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd == -1) {
		perror("server_init->socket");
		return -1;
	}
	printf("listenfd = %d\n", listenfd);

	/* 绑定服务器的ip地址和端口号 */
	memset(&srvaddr, 0, sizeof(srvaddr));
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port = htons(port);
	if (ip == NULL)
		srvaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	else
		srvaddr.sin_addr.s_addr = inet_addr(ip);
	ret = bind(listenfd, (const struct sockaddr *)&srvaddr, sizeof(srvaddr));
	if (ret == -1) {
		perror("server_init->bind");
		return -1;
	}
	printf("bind success\n");

	/* 启动监听 */
	ret = listen(listenfd, 1024);
	if (ret == -1) {
		perror("server_init->listen");
		return -1;
	}

	return listenfd;
}

/* 定义服务器等待客户端的连接请求，建立连接 */
int server_wait_client_connect(int listenfd)
{
	int connfd;
	socklen_t addrlen;
	struct sockaddr_in cltaddr;

	//accept(listenfd, NULL, NULL);
	addrlen = sizeof(cltaddr);
	connfd = accept(listenfd, (struct sockaddr *)&cltaddr, &addrlen);
	if (connfd == -1) {
		perror("accept");
		return -1;
	}
	printf("IP : %s connet success connfd = %d\n", inet_ntoa(cltaddr.sin_addr), connfd);

	return connfd;
}

int main()
{
    int listenfd = server_init(NULL, 8888);
    if(-1 == listenfd){
        return -1;
    }
    
    //构建集合
    fd_set readfds, backfds;
    //readfds是操作的集合,backfds是备份集合
    FD_ZERO(&backfds);
    //把关注的文件描述符添加到备份集合
    FD_SET(listenfd, &backfds);
    //记录文件描述符的个数
    int nfds = listenfd + 1;
    int ret = -1;

    char buf[32];
    struct timeval tv = {5, 0};
    while(1){
        //设置操作的集合
        readfds = backfds;
        //select会阻塞循环检测关注的IO集合
        ret = select(nfds, &readfds, NULL, NULL, &tv);
        if(-1 == ret){
            perror("select");
            return -1;
        }
        if(0 == ret){
            tv.tv_sec = 2;
            printf("timeout tv.sec:%ld\n", tv.tv_sec);
            continue;
        }
        
        //遍历文件描述符是否还在集合中
        for(int fd = 0; fd < nfds; fd++){
            if(!FD_ISSET(fd, &readfds))
                continue; //不在集合中就结束本次循环
            //判断是否是listenfd准备就绪
            if(fd == listenfd){
                //接收新的连接
                int confd = server_wait_client_connect(fd);
                //将通信套接字confd加入备份集合
                FD_SET(confd, &backfds);
                //集合内的文件描述符总数+1
                //nfds++;
				nfds = nfds > confd ? nfds: (confd+1);
            }else{
                //处理通信套接字
                ret = read(fd, buf, 32);
                if(ret <= 0){
                    //将对应通信套接字从集合中去除
                    FD_CLR(fd, &backfds);
                    //将对应套接字关闭
                    close(fd);
                    continue;
                }
                write(fd, buf, 32);
            }
        }


    }
    close(listenfd);
}
