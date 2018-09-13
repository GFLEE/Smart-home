#include <stdio.h>

int main()

{
	
	
	char arr[4]={'d','1','8','\0'};
	
	int sum=((int)arr[1])*10+(int)arr[2];
	
	sum-=528;
	printf("sum= %d\n",sum);
	
	
	return 0;
}