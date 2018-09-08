#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <strings.h>


int main(void)
{
	
	int fd_socket = socket(AF_INET,SOCK_DGRAM,0);
	if(fd_socket == -1)
	{
		printf("create scoket failed\n");
		return -1;
	}
	
	
	struct sockaddr_in bind_addr,client_addr;
	bind_addr.sin_family = AF_INET;
	bind_addr.sin_port = htons(2234);
	bind_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	
	int len = sizeof(bind_addr);
	
	bind(fd_socket,(struct sockaddr *)&bind_addr,len);
	char buf[10] = {0};
	
	recvfrom(fd_socket,buf,10,0,(struct sockaddr *)&client_addr,&len);
	
	printf("Message :%s\n",buf);
	
	return 0;
	
	
}