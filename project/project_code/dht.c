
#include "head.h"

int fd;

//初始化串口
void init_serial(int fd);


/**
功能：自定义读数据函数，确保数据读完整
参数：buf 数据缓冲区，即读到的数据保存到哪里去
参数：len 想要读的字节数
*/
void myread(char *buf,int len);


int dht(int argc,char *argv[])
{

    int x,y;
	int te,hu;
	//1.打开串口 // argv[1]: /dev/ttySAC1   /dev/s3c2410_serial1
	fd = open("/dev/ttySAC1",O_RDWR);
	if(fd == -1)
	{
		perror("open serial error");
		return 1;
	}
	//2.初始化串口
	init_serial(fd);
	unsigned char buffer[9]={0}; 

	while(1)
	{

		/* touch(&x,&y);
		 
		*/
		if(temp_flag==1)
		{
			home();
			break;
		}
		
		printf("collecting dht data.............\n");
		read(fd,buffer,sizeof(buffer));
		printf("buffer2 = %s\n",buffer);
		
		te=(((int)buffer[1])*10+(int)buffer[2])-528;    //整数温度
		
	    hu=(((int)buffer[5])*10+(int)buffer[6])-528;    //整数湿度


		//show pictures by temp/hum;
		if((te==25)&&(hu==40))
		{
			lcd_draw_jpg(0,0,"temp.jpg",NULL,0,0);
			
		}
		else if((te==24)&&(hu==46))
		{
			lcd_draw_jpg(0,0,"temp2.jpg",NULL,0,0);
			
		}
		else if((te==23)&&(hu==48))
		{
			lcd_draw_jpg(0,0,"temp3.jpg",NULL,0,0);
			
		}
		else if((te==23)&&(hu==47))
		{
			lcd_draw_jpg(0,0,"temp4.jpg",NULL,0,0);
			
		}
		else if((te==23)&&(hu==50))
		{
			lcd_draw_jpg(0,0,"temp50.jpg",NULL,0,0);
		}
		else if((te==23)&&(hu==51))
		{
			lcd_draw_jpg(0,0,"temp5.jpg",NULL,0,0);
		}
		else if((te==23)&&(hu==52))
		{
			lcd_draw_jpg(0,0,"temp6.jpg",NULL,0,0);
		}
		else if((te==23)&&(hu==53))
		{
			lcd_draw_jpg(0,0,"temp7.jpg",NULL,0,0);
		}
		else if((te==23)&&(hu==54))
		{
			lcd_draw_jpg(0,0,"temp8.jpg",NULL,0,0);
		}
		else if((te==23)&&(hu==55))
		{
			lcd_draw_jpg(0,0,"temp9.jpg",NULL,0,0);
		}
		else if((te==23)&&(hu==56))
		{
			lcd_draw_jpg(0,0,"temp10.jpg",NULL,0,0);
		}
		else if((te==23)&&(hu==57))
		{
			lcd_draw_jpg(0,0,"temp11.jpg",NULL,0,0);
		}
		else if((te==23)&&(hu==58))
		{
			lcd_draw_jpg(0,0,"temp12.jpg",NULL,0,0);
		}
		else if((te==23)&&(hu==59))
		{
			lcd_draw_jpg(0,0,"temp13.jpg",NULL,0,0);
		}
		else{
			
			lcd_draw_jpg(0,0,"temp4.jpg",NULL,0,0);
		}
		
		
	

		//通过解析匹配图片并显示
	}
	//4.关闭串口
	close(fd);

	return 0;
}


/* 设置参数:115200速率 */
void init_serial(int fd)
{    
	//声明设置串口的结构体
	struct termios termios_new;
	//先清空该结构体
	bzero( &termios_new, sizeof(termios_new));
	//	cfmakeraw()设置终端属性，就是设置termios结构中的各个参数。
	
	cfmakeraw(&termios_new);
	//设置波特率
	//termios_new.c_cflag=(B9600);
	cfsetispeed(&termios_new, B115200);
	cfsetospeed(&termios_new, B115200);
	//CLOCAL和CREAD分别用于本地连接和接受使能，因此，首先要通过位掩码的方式激活这两个选项。    
	termios_new.c_cflag |= CLOCAL | CREAD;
	//通过掩码设置数据位为8位
	termios_new.c_cflag &= ~CSIZE;
	termios_new.c_cflag |= CS8; 
	//设置无奇偶校验
	termios_new.c_cflag &= ~PARENB;
	//一位停止位
	termios_new.c_cflag &= ~CSTOPB;
	
	tcflush(fd,TCIFLUSH);
	// 可设置接收字符和等待时间，无特殊要求可以将其设置为0
	termios_new.c_cc[VTIME] = 10;
	termios_new.c_cc[VMIN] = 1;
	// 用于清空输入/输出缓冲区
	tcflush (fd, TCIFLUSH);
	//完成配置后，可以使用以下函数激活串口设置
	if(tcsetattr(fd,TCSANOW,&termios_new) )
		printf("Setting the serial1 failed!\n");

}








