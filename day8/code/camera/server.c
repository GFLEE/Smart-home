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
	 //1.买手机
	int fd_socket = socket(AF_INET,SOCK_DGRAM,0);
	if(fd_socket == -1)
	{
		printf("购买手机失败\n");
		return -1;
	}
	
	//设置自己的手机卡
	struct sockaddr_in bind_addr;
	bind_addr.sin_family = AF_INET;
	bind_addr.sin_port = htons(6666);
	bind_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//Rose的IP
	
	int len = sizeof(bind_addr);
	char buf[20] = {0};
	
	while(1)
	{
		//直接打电话
		
		bzero(buf,sizeof(buf));
		printf("jack please input :");
		scanf("%s",buf);
		sendto(fd_socket,buf,20,0,(struct sockaddr *)&bind_addr,sizeof(bind_addr));
		bzero(buf,sizeof(buf));
		
		recvfrom(fd_socket,buf,20,0,(struct sockaddr *)&bind_addr,&len);
		printf("Rsoe is %s\n",buf);
		if(strcmp(buf,"byebye") == 0)
			break;
		
	}
	
	 return 0;
 }