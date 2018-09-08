#include "head.h"


void *ts_func(void *arg)
{
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
}



int main(int argc,char **argv)
{
	
	pthread_t tid;
	pthread_create(&tid,NULL,ts_func,NULL);

		lcd_draw_jpg(0,0,"/touch.jpg",NULL,0,0);
		do_camera();
		
		
		pthread_join(tid,NULL);

		

	
	return 0;
	}













