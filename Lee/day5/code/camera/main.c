#include "head.h"

/*
编译代码
	arm-linux-gcc main.c lcd.c yuyv.c -o main -I./libjpeg -L./libjpeg -ljpeg -lapi_v4l2_arm
*/


void *ts_func(void *arg)
{
	int x,y;
	while(1)
	{
		touch(&x,&y);
		if(x>700&&y<240)
		{
			flage=2;     //拍照
			printf("shootshootshootshootshoot\n");
			}else if(x>700&&y>240){
				
				flage=3;   //退出
			}
	}
}



int main(int argc,char **argv)
{
	
	pthread_t tid;
	pthread_create(&tid,NULL,ts_func,NULL);
	


	

		lcd_draw_jpg(0,0,"./touch.jpg",NULL,0,0);
		do_camera();
		
		pthread_join(tid,NULL);

		

	
	return 0;
	}













