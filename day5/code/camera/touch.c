#include "head.h"

int touch(int *x,int *y)
{
	    int ts_fd=open("/dev/input/event0",O_RDWR);

		if(ts_fd==0)
		{
			printf("open touch screen failed!\n");
			return -1;
		}
	
		struct input_event myts;
	
		while(1)
		{
		 
		read(ts_fd,&myts,sizeof(myts));

		 if(myts.type==EV_ABS && myts.code == ABS_X)
		{
	
		*x= myts.value;             // 存放触摸屏x轴的数值
	
		}
	//=======================================================

		 if(myts.type==EV_ABS && myts.code == ABS_Y)
		{
		*y= myts.value;           
	
		}
		
		if(myts.type == EV_KEY && myts.code == BTN_TOUCH && myts.value == 0)
		{
		
		//	printf("(x,y) = (%d,%d)\n",x,y);
			break;

		}

		 
	 }
	
	return 0;
}


