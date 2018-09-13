#include "head.h"


void *ts_func(void *arg)
{
	/*
	int x,y;
	while(1)
	{
		touch(&x,&y);
		if(x>700&&y<240)
		{
			flage=2;     //拍照
			printf("Capturing photo Capturing photo Capturing photo...............\n");
			}else if(x>700&&y>240){
				
				flage=3;   //退出
			}
		
	}
	
	*/
	
	
			
		//==============================================
		
		int len=sizeof(phoneaddr);
		char recv_buf[50]={0};
		int music_flag=1;
		int con_st=1;
			while(1)
			{
				
			bzero(recv_buf,50);
			recvfrom(iphonex,recv_buf,sizeof(recv_buf),0,(struct sockaddr*)&phoneaddr,&len);
			printf("recv_buf is %s\n",recv_buf);
			
			
			 if(strcmp(recv_buf,"ENTER_KUGOU")==0)
			 {
				 //Run
				 
				 system("madplay music.mp3 &");  //后台运行
				music_flag=1;
				
				 
				 
			 }
			 else if(strcmp(recv_buf,"BACK")==0){
				

				system("killall -9 madplay &");   //结束进程

				
				
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
									//  STOP/CONTINUE
				 
			 }
			
			else if(strcmp(recv_buf,"MUSIC_PREV")==0)
			{
				// PRE
					if(music_flag==1)
					{
					
					system("killall -9 madplay &");   //结束进程

					system("madplay music2.mp3 &");  //后台运行
						music_flag=0;
					}
					else{
					system("killall -9 madplay &");   //结束进程

					system("madplay music.mp3 &");  //后台运行
					music_flag=1;

					}
					

				
			} else if(strcmp(recv_buf,"MUSIC_NEXT")==0){
				
					if(music_flag==1)
					{
					system("killall -9 madplay &");   //结束进程
					system("madplay music2.mp3 &");  //后台运行
						music_flag=0;
					}
					else{
					system("killall -9 madplay &");   //结束进程
					system("madplay music.mp3 &");  //后台运行
					music_flag=1;	// NEXT;
					}
				
			}
	
			}
}


int main(int argc,char **argv)
{
	
		pthread_t tid;
		pthread_create(&tid,NULL,ts_func,NULL);

		udp_init();

		lcd_draw_jpg(0,0,"/touch.jpg",NULL,0,0);
		do_camera();
		
		
		pthread_join(tid,NULL);

		

	
	return 0;
}













