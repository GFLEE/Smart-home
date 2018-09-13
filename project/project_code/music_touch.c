#include "head.h"

/*

music display

*/

void *music_touch(void * arg)
{
	
			
	int x,y;
		while(1)
		{	
		
			touch(&x,&y);
			
		if((x>=360&&x<=460)&&(y>=360&&y<=470))
		 {
			 printf("tog_flag= %d....\n",tog_flag);

			 tog_flag=1;
			 system("killall -9 madplay");
			 home();
			 break;
		 }
		 else{
			 

			 tog_flag=0;
			
	
		
		 }
		
		}		
	



}