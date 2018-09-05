/*************************************************************************
    > File Name: copy.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Tue 04 Sep 2018 06:41:21 PM PDT
 ************************************************************************/
#include "head.h"


int main(int argc,char **argv)
{
	int i;
	int clr;
	int file_flag;
	char buf[100]={0};
	printf("argc:  %d\n",argc);
	printf("argv[3] is  %s\n",argv[3]);

//	int file_flag=open("argv[1]",O_RDWR|O_CREAT,0777);
	if(argc!=3)
	{
		printf("Error!\n");
		return -1;
	}
     
	int file_falg=open(argv[1],O_RDWR|O_CREAT,0777);
	if(file_flag==-1)
	{
	printf("open/creat file failed!");

	}

	close(file_flag);

	file_flag=open("./test.txt",O_RDWR);

	int new_flag=open(argv[2],O_RDWR|O_CREAT,0777);
	
	if(new_flag==-1)
	{printf("new file_creat error!");	}
 //int read_flag=	read(file_flag,buf,100);
int read_flag=1;
 while(read_flag!=0)
 {
	for(clr=0;clr<100;clr++)
	{
		buf[clr]='0';
	}
	 
	 read_flag=read(file_flag,buf,100);

	write(new_flag,buf,read_flag);
	


 }

	close(file_flag);
	close(new_flag);

	return 0;
}
