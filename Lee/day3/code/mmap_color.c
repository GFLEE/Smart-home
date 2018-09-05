#include "head.h"

int main(int argc,char **argv)
{
	//打开lcd
 int lcd_fd = open("/dev/fb0",O_RDWR);
	if(lcd_fd == -1)
	{
		printf("open lcd failed\n");
		return -1;
	}
	
	//根据lcd大小分配显存
	char * FB = mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,lcd_fd,0);
	if(FB == NULL)
	{
		printf("creat mmap failed\n");
		return -1;
	}
	
	//定义颜色
	int red = 0x00ff0000;//红色
	int blue= 0x4030ff;


	//将颜色写入显存
	int i,j;

	while(1)
	{
		
	
	/*    sleep(1);
	  
		
			for(i=0;i<240;i++)
	{
		for(j=0;j<800;j++)
		{
			//将颜色复制到显存
			memcpy(FB+j*4+400*i*4 ,&red,4);
		}
	}
	

	sleep(1);

	*/


	for(i=0;i<340;i++)
	{
		for(j=0;j<200;j++)
		{
			//将颜色复制到显存
			memcpy(FB+j*4+200*i*4 ,&blue,4);
		}
		
		sleep(1);
		for(j=200;j<400;j++)
		{
			//将颜色复制到显存
			memcpy(FB+j*4+200*i*4 ,&red,4);
		}
		sleep(1);
		for(j=400;j<600;j++)
		{
			//将颜色复制到显存
			memcpy(FB+j*4+200*i*4 ,&blue,4);
		}
		sleep(1);
		for(j=600;j<800;j++)
		{
			//将颜色复制到显存
			memcpy(FB+j*4+200*i*4 ,&red,4);
		}
		sleep(1);
		
	}


		
	}


	//解除映射
	munmap(FB,800*480*4);
	return 0;
}
