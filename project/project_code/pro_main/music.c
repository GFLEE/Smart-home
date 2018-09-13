#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	
	system("madplay music.mp3 &");  //后台运行
	sleep(1);
	
	system("killall -STOP madplay &");
	sleep(1);
	
	system("killall -CONT madplay &");     //继续播放
	sleep(1);
	
	system("killall -9 madplay &");   //结束进程
	
	return 0;
}