#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == listenfd)
	{
		perror("socket");
		return -1;
	}
/*
	struct sockaddr_in serveraddr = {
		.sin_family = AF_INET,
		.sin_addr.s_addr = inet_addr("127.0.0.1");
		.sin_port = htons(8888);
	};
*/
 
	struct sockaddr_in serveraddr = {0};
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = INADDR_ANY;//inet_addr("0.0.0.0");////0
	serveraddr.sin_port = htons(8888);
	
	int len = sizeof(serveraddr);
	if(-1 == bind(listenfd, (struct sockaddr*)&serveraddr, len) )
	{
		perror("connect");
		return -1;
	}

	listen(listenfd, 10);//start to wait
	printf("wating ................ !\n");

	int clientfd = accept(listenfd, NULL, NULL);//if someone connected,then create a new socket(clientfd) and return

	while(1)
	{
		char buf[100] = {0};
		int ret = read(clientfd, buf, 100);
		if(0 == ret)
			break;

		printf("recv[%d]: %s\n", ret, buf);
	}

	close(listenfd);
	close(clientfd);
}
