#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <strings.h>
/*


	server 

*/

int main(void)
{
	
	//  1. create a socket
	
	int fd_socket = socket(AF_INET,SOCK_DGRAM,0);  
	//argu1: ipv4    ,argu2:udp  ,argu3:other protocal
	if(fd_socket==-1){
		
		printf("create socket failed!");
		return -1;
		
	}
	
	
	// 2. bind ip,port to the socket
	
	struct sockaddr_in bind_addr,client_addr;
	bind_addr.sin_family = AF_INET;
	bind_addr.sin_port =  htons(2234);
    bind_addr.sin_addr.s_addr = inet_addr("127.0.0.1");	
	int c=sizeof(bind_addr);
	
	
	
	
	// 3.send data;
	char buf[20] = "Hello";
	sendto(fd_socket,buf,20,0,(struct sockaddr *)&bind_addr,sizeof(bind_addr));
	
	
	
	return 0;
}
