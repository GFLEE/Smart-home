#include "head.h"

//----------function -----
int start(void);
int home(void);
void temp(void);
void *ts_func(void *arg);
void *shoot(void *args);
void *music(void *arg);
void create_shoot(void);
void create_music(void);



//=================线程1： 触摸测试&拍照============
void *ts_func(void *arg)
{
	int x,y;

	int len = sizeof(phoneaddr);
	char recv_buf[50] = {0};
	int music_flag=1;
	int con_st=1;

		bzero(recv_buf,50);
		//接收手机发送过来的指令，获取手机的IP和端口号
		recvfrom(iphonex,recv_buf,sizeof(recv_buf),0,(struct sockaddr *)&phoneaddr,&len);
		printf("recv_buf is %s\n",recv_buf);
		
		while(1)
	{
		bzero(recv_buf,50);
		//接收手机发送过来的指令，获取手机的IP和端口号
		recvfrom(iphonex,recv_buf,sizeof(recv_buf),0,(struct sockaddr *)&phoneaddr,&len);
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
				
			}else{
				
				touch(&x,&y);
				if(x>700&&y<240)
				{
				flage=2;     //拍照
				printf("Shooting photo Shooting photo Shooting photo...............\n");
				}else if(x>700&&y>240){
				
				flage=3;   //退出	
				}
				
				}
		
		
		
		
		
		
		
		//.......................................
		
		
	
	
	}
	
}	
		
//=====================================================================
	
		
//------------------------temprature and hum------------------
  void temp()
  {
		int x,y;
		printf("hello temp\n");
		// lcd_draw_jpg(0,0,"temp.jpg",NULL,0,0);
 
		dht();
  }
//---------------------------strart ------------------

int start(void)
{
	int x,y;
	lcd_draw_jpg(0,0,"welcome.jpg",NULL,0,0);
	 while(1)
	{
		touch(&x,&y);
		if(x|y)
		{
			home();
		}
	}
	
	return 0;
}


		
		
		
int home(void)
{
     int x,y;
	
	  lcd_draw_jpg(0,0,"main.jpg",NULL,0,0);
	  
	 while(1)
	{
		touch(&x,&y);

		if((x>=170&&x<=260)&&(y>=133&&y<=220)) // camera monitoring
		{
			
			
		//	lcd_draw_jpg(0,0,"monitor.jpg",NULL,0,0);
		//	do_camera();
		   
			create_shoot();
			printf("camera monitoring\n");
			
		}
		else if((x>=552 && x<= 630 )&&(y>= 135&& y<= 220)){     //mp3 play
			
			create_music();
			printf("mp3 play\n");
		}
		else if((x>= 168 && x<= 245)&&(y>= 270&& y<= 335))   //T&H display
		{
		//	lcd_draw_jpg(0,0,"temp.jpg",NULL,0,0);
			temp();
			printf("T&H display\n");
			
		}
		else if((x>= 555 && x<= 635 )&&(y>=272 && y<=360 ))    //images display
		{
			printf("images display\n");
		}
		else if((x>=360 && x<=440 )&&(y>=210 && y<=310 ))   // Exit
		{
			start();
			printf("Exit\n");
			
		}
		
	}
return 0;

}
		

void create_shoot()
{
		   pthread_t tid_shoot;
		
		   udp_init();
			
		   pthread_create(&tid_shoot,NULL,ts_func,NULL);
		   lcd_draw_jpg(0,0,"monitor.jpg",NULL,0,0);
		   	do_camera();
			
	pthread_join(tid_shoot,NULL);

}

void create_music()
{
		   pthread_t tid_music;
	
		   pthread_create(&tid_music,NULL,music,NULL);
			
	 pthread_join(tid_music,NULL);

}
	
//===================mudic thread===============	
		
//=============================Music function==========================


//------------------------------------------------------------------		
		
		
int main(int argc,char **argv)
{
	
		  //monitor thread
	    //start

	       start();
		   

	
		
						
		
	
		
	
	
	//start();
		
	//	dht();
	//	do_camera();



	
	

		

	
	return 0;
}













