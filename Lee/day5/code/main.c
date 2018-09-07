#include "head.h"

int main(int argc,char **argv)
{
	int i,jpg_flag=0;
    int x,y;
	 char* pic_path[3] = {"./jpeg/1.jpg","./jpeg/2.jpg","./jpeg/3.jpg"};
	 	lcd_open("/dev/fb0");
		lcd_draw_jpg(0,0, pic_path[0],NULL,0,0);
		
		    while(1)
			{
				
				 touch(&x,&y);
			 printf("(x,y) = (%d,%d)\n",x,y);
			if(x<=100&&(y>=160&&y<=320))
			{
				jpg_flag--;

				  if(jpg_flag<0)
				  {
					  jpg_flag=2;
				  }
			lcd_draw_jpg(0,0, pic_path[jpg_flag],NULL,0,0);

			}
			
			else if((x>=700&x<800)&&(y>=160&&y<=320))
			{
				 jpg_flag++;
				 if(jpg_flag>=3)
				  {
					  jpg_flag=0;
				  }
		lcd_draw_jpg(0,0, pic_path[jpg_flag],NULL,0,0);
			}
			else{;}
			
		
			}
		

		
				
			
		

		 
	
	
	
	
	
	
	
	return 0;
}