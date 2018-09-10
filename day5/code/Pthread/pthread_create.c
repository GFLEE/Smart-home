#include <stdio.h>
#include <pthread.h>

void *func(void *arg)
{
	while(1)
	{
		printf("儿子在上学......\n");
		sleep(1);
	}
}




int main(void)
{
	//  1.创建线程号
	
		pthread_t tid;
		pthread_create(&tid,NULL,func,NULL);
	
	while(1)
	{
		
		printf("爸爸在睡觉....\n");
		sleep(1);
		
	}
	
	
	
	
	
	
	
	return 0;
}