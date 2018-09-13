#include "head.h"


void music(void)
{
		//==============================================
		
			printf("=====Into mp3 play system========\n");
		
			int len=sizeof(phoneaddr);
			char recv_buf[50]={0};
			int music_flag=1;
			int con_st=1;
		    int x,y;
			
			
			bzero(recv_buf,50);
		    //接收手机发送过来的指令，获取手机的IP和端口号
		    recvfrom(iphonex,recv_buf,sizeof(recv_buf),0,(struct sockaddr *)&phoneaddr,&len);
		    printf("recv_buf is %s\n",recv_buf);
			
			
			
			
			while(1)
			{
				printf("tog_flag= %d\n",tog_flag);
				
				if(tog_flag==1)
				{
					printf("music bye bye...........\n");
					tog_flag=0;
					home();
					break;
					
				}
				
		
			bzero(recv_buf,50);
		    //接收手机发送过来的指令，获取手机的IP和端口号
		    recvfrom(iphonex,recv_buf,sizeof(recv_buf),0,(struct sockaddr *)&phoneaddr,&len);
		    printf("recv_buf is %s\n",recv_buf);
			
			if(strcmp(recv_buf,"ENTER_KUGOU")==0)
			 {
				 //Run
				 
				 system("madplay hello.mp3 &");  //hello kugo!				
				 
			 }
			
			 else if(strcmp(recv_buf,"MUSIC_PLAY")==0)
			 {
				 system("madplay music.mp3 &");  //后台运行
				 
			 }
			 else if(strcmp(recv_buf,"BACK")==0){
				
				system("killall -9 madplay"); 
				home();
				  //结束进程
				
				
				
				//  BACK
			 }
			 else if(strcmp(recv_buf,"MUSIC_STOP_CONT")==0)
			 {
				 if(con_st==1)
				 { system("killall -STOP madplay &");
					con_st=0;
					}
			else if(con_st==0){
					system("killall -CONT madplay &");     //继续播放
					con_st=1;

			}
				 
			 }
			
			else if(strcmp(recv_buf,"MUSIC_PREV")==0)
			{
				// PRE
					if(music_flag==1)
					{
					
					system("killall -9 madplay");   //结束进程

					system("madplay music2.mp3 &");  //后台运行
						music_flag=0;
					}
					else{
						
					system("killall -9 madplay");   //结束进程
					
					system("madplay music.mp3 &");  //后台运行
					music_flag=1;

					}
					

				
			} else if(strcmp(recv_buf,"MUSIC_NEXT")==0){
				
					if(music_flag==1)
					{
									
					system("killall -9 madplay");   //结束进程
					system("madplay music2.mp3 &");  //后台运行
						music_flag=0;
					}
					else{
						
					system("killall -9 madplay");   //结束进程
					system("madplay music.mp3 &");  //后台运行
					music_flag=1;	// NEXT;
					}
				
			}
			else{
				;
	
			}
			
			
			
			
}
}







