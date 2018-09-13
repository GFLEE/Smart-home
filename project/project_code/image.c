#include "head.h"  
/*



*/
//void *image(void *arg)

void camera_shoot();
void saved_album();

void album_choose()
{
    int x,y;
	lcd_draw_jpg(0,0,"album_choose.jpg",NULL,0,0);
		
		    while(1)
			{
				
				 touch(&x,&y);
				printf("(x,y) = (%d,%d)\n",x,y);
			if((x>137&&x<285)&&(y>170&&y<280))
			{
				 camera_shoot();


			}
			else if((x>495&&x<632)&&(y>171&&y<272))
			{
				  saved_album();

			}
			else if((x>336&&x<417)&&(y>367&&y<480)){
			
				      home();
				
				}
		
			}
	
}



void camera_shoot()
{
	int i,jpg_flag=0;
    int x,y;
	lcd_draw_jpg(0,0,"proc.jpg",NULL,0,0);
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
			
				album_choose();
				
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





void saved_album()
{
	
	int i,jpg_flag=0;
	lcd_draw_jpg(0,0,"proc.jpg",NULL,0,0);
    int x,y;
	 char* pic_path[5] = {"/jpeg/1.jpg","/jpeg/2.jpg","/jpeg/3.jpg","/jpeg/4.jpg","/jpeg/5.jpg"};
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
			
				album_choose();
				
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
	
}



void image()
{
	
	album_choose();
	
}










