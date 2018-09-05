/*************************************************************************
    > File Name: mmap.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 05 Sep 2018 01:30:21 AM PDT
 ************************************************************************/
#include "head.h"
int main(void)
{

	int i,j;
//==============open LCD==========================
int lcd_fd = open("/dev/fd0",O_RDWR);
if(lcd_fd==-1)
{
	printf("failed!");
}



//================distribute 显存==================================

char *FB=mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,lcd_fd,0);
	
if(FB==NULL)
{
	printf("creat mmap failed!");
	return -1;
}

//define colors
int red=0x00ff0000;  //red

//write the color into the xiancun

for(i=0;i<480;i++)
{

	for(j=0;j<800;j++)
	{
		memcpy(FB+j*4+800*i*4,&red,4); //copy color to xiancun
	}
}


//jiechu yinshe

munmap(FB,800*480*4);

	return 0;
}
