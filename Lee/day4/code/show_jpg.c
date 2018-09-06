#include <stdio.h>
#include <pthread.h>

int main(int argc,char **argv)
{

	lcd_open("/dev/fb0");
	
	int i = 0;
	
    char* pic_path[3] = {"./jpeg/1.jpg","./jpeg/2.jpg","./jpeg/3.jpg"};
	
	while(1)
	{
		if(i == 3)
		{
			i = 0;
		}
		lcd_draw_jpg(0,  0, pic_path[i], NULL, 0, 0);
		pthread_testcancel();
		sleep(1);
		i++;	
	}
		
	return 0;
}