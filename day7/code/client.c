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
	
	//设置自己的手机卡,设置来电显示结构体
	struct sockaddr_in bind_addr,client_addr;
	bind_addr.sin_family = AF_INET;
	bind_addr.sin_port = htons(6666);
	bind_addr.sin_addr.s_addr = inet_addr("192.168.214.128");//任何人都能打电话给我
	
	int len = sizeof(bind_addr);
	//绑定手机
	bind(fd_socket,(struct sockaddr *)&bind_addr,len);
	char buf[20] = {0};
	while(1)
	{
		//接收jack的电话
		bzero(buf,sizeof(buf));//清空缓存
		recvfrom(fd_socket,buf,20,0,(struct sockaddr *)&client_addr,&len);
		printf("Jack say :%s\n",buf);
		if(strcmp(buf,"byebye")==0)//匹配字符串，如果相等则退出
			break;
		
		
		bzero(buf,sizeof(buf));
		printf("Rose please input :");
		scanf("%s",buf); 
		sendto(fd_socket,buf,20,0,(struct sockaddr *)&client_addr,len);
		
	}
	
	
	return 0;
	
	
}