/*************************************************************************
    > File Name: flag.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Tue 04 Sep 2018 04:23:20 AM PDT
 ************************************************************************/
#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <stdio.h>

#include <unistd.h>


int main()
{

	int lcd_flag=open("/dev/fb0",O_RDWR);
	if(lcd_flag==-1)
	{
		printf("open LCD failed!");
		return 0;
	}


	char black_r=0;
	char black_g=0;
	char black_b=0;

	char red_r=255;
	char red_g=0;
	char red_b=0;

	char ye_r=255;
	char ye_g=255;
	char ye_b=0;

	int m,n,k;

	char black[800*160*4]={0};
	char red[800*160*4]={0};
	char yellow[800*160*4]={0};

	
	for(m=0;m<800*160*4;m+=4)
	{
	
		black[m+0]=black_b;
		black[m+1]=black_g;
		black[m+2]=black_r;
		black[m+3]=0x0;


	}


	//for(n=0;n<800*160*4;n+=4)
	for(n=0;n<800*160*4;n+=4)
	{
		red[n+0]=red_b;
		red[n+1]=red_g;
		red[n+2]=red_r;
		red[n+3]=0x0;
	}


	for(k=0;k<800*160*4;k+=4)
	{
        yellow[k+0]=ye_b;
		yellow[k+1]=ye_g;
		yellow[k+2]=ye_r;
		yellow[k+3]=0x0 ;

	}



	write(lcd_flag,black,800*160*4);
	write(lcd_flag,red,800*160*4);
   	write(lcd_flag,yellow,800*160*4);

	close(lcd_flag);






return 0;

}
