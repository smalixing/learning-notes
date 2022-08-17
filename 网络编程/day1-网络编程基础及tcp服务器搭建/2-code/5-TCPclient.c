#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
	if(3 != argc)
	{
		printf("Usage: <%s> <IP> <PORT>\n", argv[0]);
		return -1;
	}

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sockfd)
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
	serveraddr.sin_family = AF_INET,
	serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
	serveraddr.sin_port = htons( atoi(argv[2]) );
	
	int len = sizeof(serveraddr);
	if(-1 == connect(sockfd, (struct sockaddr*)&serveraddr, len) )
	{
		perror("connect");
		return -1;
	}

	while(1)
	{
		write(sockfd, "hello", 5);
		sleep(1);
	}

	close(sockfd);
}
