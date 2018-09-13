#include "head.h"

/*

music display

*/

void *music_touch(void * arg)
{
	
			
	int x,y;
	music_flag=0;
		while(1)
		{	
			
		touch(&x,&y);
		if((x>=360&&x<=460)&&(y>=360&&y<=470))
		 {
			 
			 music_flag=1;
		
		 }
		 else{
			music_flag=0;
	
		
		 }
		
		}		
	



}