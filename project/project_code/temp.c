#include "head.h"

/*

temp display

*/

void *temp(void * arg)
{
	
			
	int x,y;
	temp_flag=0;
		while(1)
		{	
			
		touch(&x,&y);
		if((x >= 370 && x <= 450)&&(y >= 300&& y <= 390))
		 {
			 
			 temp_flag=1;
		
		 }
		 else{
			temp_flag=0;
		//	dht();
		
		 }
		
		}		
	
	//pthread_join(tid_temp_touch,NULL);


}