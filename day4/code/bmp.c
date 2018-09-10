
#include "head.h"
int main(int argc,char **argv)
{
	//1.打开lcd
	int lcd_fd = open("/dev/fb0",O_RDWR);
	if(lcd_fd == -1)
	{
		printf("open lcd failed\n");
		return -1;
	}

	//2.打开bmp图片
	int bmp_fd = open("./1.bmp",O_RDWR);
	if(bmp_fd == -1)
	{
		printf("open bmp failed\n");
		return -1;
	}

	//3.跳过54字节,文件头信息
	lseek(bmp_fd,54,SEEK_SET);//从头开始跳

	//4.读取bmp图片
	char bmp_buf[800*480*3]= {0};
	read(bmp_fd,bmp_buf,sizeof(bmp_buf));

	//5.将三字节的bmp通过移位的方式合成四字节
	int lcd_buf[800*480] = {0};
	int i,j;
	for(i=0,j=0;i<800*480;i++,j+=3)
		lcd_buf[i] = bmp_buf[j+0]<<0 | bmp_buf[j+1]<<8 | bmp_buf[j+2]<<16 |0x0<<24;
	
	//6.将图片翻转
	
	int show_buf[800*480]={0};
	int x;
	int y;
	for(y=0;y<480;y++)
	{
		for(x=0;x<800;x++)
		{
			show_buf[(479-y)*800+x] = lcd_buf[y*800+x];
		}
	}
	
	//7.将lcd_buf写入到lcd
	write(lcd_fd,show_buf,sizeof(lcd_buf));
	
	return 0;
}


