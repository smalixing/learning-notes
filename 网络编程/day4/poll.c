#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */

#include <poll.h>

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
	int ret;
	int listenfd;
	int connfd;
	char buf[256];
	int nfds;
	int i;
	int j;
	int fd;
	struct pollfd fds[128];


	/* 1. 服务器的初始化 */
	listenfd = server_init("127.0.0.1", 8888);
	//listenfd = server_init(NULL, 8888);
	if (listenfd == -1)
		exit(EXIT_FAILURE);
	printf("server init success\n");

	/* 创建集合，清空集合 */
	for (i = 0; i < 128; i++)
		fds[i].fd = -1;

	/* 将文件描述符listenfd及其对应事件添加到集合fds中 */
	fds[0].fd = listenfd;
	fds[0].events = POLLIN;
	nfds = 1;

	while(1) {
		/* c， 调用poll函数，检测是否有准备就绪的事件，如果没有事件准备就绪，函数一直阻塞。如果有事件准备就绪函数返回；*/
		ret = poll(fds, nfds, 5000);
		if (ret == -1) {
			perror("poll");
			return -1;
		} else if (ret == 0) {
			printf("timeout ......\n");
			continue;
		}
		
		for (i = 0; i < nfds; i++) {
			/* 读资源准备就绪，进行读IO操作 */
			if (fds[i].revents == POLLIN) {
				fd = fds[i].fd;
				if (fd == listenfd) { 	/* 监听套接字 */
					/* 2. 服务器等待客户端的连接请求，建立连接 */
					connfd = server_wait_client_connect(listenfd);
					if (connfd == -1)
						exit(EXIT_FAILURE);
					/* 连接成功，将文件描述符connfd及其对应事件添加到集合fds中 */
					fds[nfds].fd = connfd;
					fds[nfds].events = POLLIN;
					nfds ++;
					continue;
				} //if (fd == listenfd) end

				/* 通信套接字 */
				/* 3. 服务器处理客户端的数据请求，并处理数据，反馈处理结果 */
				memset(buf, 0, sizeof(buf));
				ret = read(fd, buf, sizeof(buf));
				if (ret == -1) {
					perror("server->read");
					return -1;
				} else if (ret == 0) {
					/* 客户端退出的时候，需要将套接字从集合中删除 */
					for (j = i; j < nfds-1; j++)
						fds[j] = fds[j+1];
					close(fd);
					break;
				}
				printf("buf : %s\n", buf);

				ret = write(fd, buf, sizeof(buf));
				if (ret == -1) {
					perror("server->write");
					return -1;
				}
			} //if (fds[i].revents == POLLIN) end
			if (fds[i].events == POLLOUT) {
				/* 执行写IO操作 */
			}

		} //for (fd = 0; fd < nfds; fd++) end
	} //while(1) end

	return 0;
}
