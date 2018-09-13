#include "head.h"  
/*

	


*/
//void *image(void *arg)
void image()
{
	int i,jpg_flag=0;
    int x,y;
	 char* pic_path[5] = {"1.jpg","2.jpg","3.jpg","4.jpg","5.jpg"};
	 	//lcd_open("/dev/fb0");
		lcd_draw_jpg(0,0, pic_path[0],NULL,0,0);
		
		    while(1)
			{
				
				 touch(&x,&y);
					printf("(x,y) = (%d,%d)\n",x,y);
			if(x>640&&(y<160))
			{
				jpg_flag--;

				  if(jpg_flag<0)
				  {
					  jpg_flag=4;
				  }
				lcd_draw_jpg(0,0, pic_path[jpg_flag],NULL,0,0);

			}
			
			else if(x>640&&(y>160&&y<320)){
			
				home();
				
				}
				
			else if(x>640&&(y>320&&y<480))
			{
				 jpg_flag++;
				 if(jpg_flag>=5)
				  {
					  jpg_flag=0;
				  }
			lcd_draw_jpg(0,0, pic_path[jpg_flag],NULL,0,0);
			}
			
			
		
			}
		
	
	
	
	
//	return 0;
}