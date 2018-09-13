#include "head.h"

//----------function -----
int start(void);
int home(void);
void *ts_func(void *arg);
void *shoot(void *args);
void music(void);
void *temp(void *arg);
void *music_touch(void * arg);
void image(void);
void create_shoot(void);
void create_music(void);
void create_temp(void);



//=================线程1： 触摸测试&拍照============
void *ts_func(void *arg)
{
	int x,y;

	int len = sizeof(phoneaddr);
	char recv_buf[50] = {0};

			bzero(recv_buf,50);
							//接收手机发送过来的指令，获取手机的IP和端口号
		recvfrom(iphonex,recv_buf,sizeof(recv_buf),0,(struct sockaddr *)&phoneaddr,&len);
		printf("recv_buf is %s\n",recv_buf);
		while(1)
		{
				touch(&x,&y);
				if(x>700&&y<240)
				{
				
				flage=2;     //拍照
				
				printf("Shooting photo Shooting photo Shooting photo...............\n");
				}else if(x>700&&y>240){
				
				flage=3;   //退出	
				}
				
				
		
		}
	
}	
		
//=====================================================================

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
			create_shoot();
			
		}
		else if((x>=552 && x<= 630 )&&(y>= 135&& y<= 220)){     //mp3 play
		
		
			lcd_draw_jpg(0,0,"music.jpg",NULL,0,0);
			create_music();
			
			
		}
		else if((x>= 168 && x<= 245)&&(y>= 270&& y<= 335))   //T&H display
		{
			lcd_draw_jpg(0,0,"temp_welcome.jpg",NULL,0,0);
			create_temp();			
		}
		else if((x>= 555 && x<= 635 )&&(y>=272 && y<=360 ))    //images display
		{
		
		//	lcd_draw_jpg(0,0,"proc.jpg",NULL,0,0);
			image();
		}
		else if((x>=360 && x<=440 )&&(y>=210 && y<=310 ))   // Exit
		{
			start();
			
		}
		
	}
return 0;

}
		

void create_shoot()
{
		   pthread_t tid_shoot;
		   pthread_create(&tid_shoot,NULL,ts_func,NULL);
		   lcd_draw_jpg(0,0,"monitor.jpg",NULL,0,0);
		   	do_camera();
			
	pthread_join(tid_shoot,NULL);

}
//-------------------------------------------------------------
void create_music()
{
		   pthread_t tid_music;
		   pthread_create(&tid_music,NULL,music_touch,NULL);
			music();
		pthread_join(tid_music,NULL);

}
	
//===================mudic thread===============	
		
//=============================create show_images thread==========================

//------------------------------------------------------------------		

void create_temp()
{
			pthread_t tid_temp;
		   pthread_create(&tid_temp,NULL,temp,NULL);
		  lcd_draw_jpg(0,0,"temp10.jpg",NULL,0,0);

			dht();
			pthread_join(tid_temp,NULL);
	
	
}



//----------------------------------------------------------------
		
int main(int argc,char **argv)
{
	
		udp_init();
	       start();

	return 0;
}













