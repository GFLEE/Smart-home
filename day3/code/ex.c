/*************************************************************************
    > File Name: ex.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 05 Sep 2018 12:16:22 AM PDT
 ************************************************************************/
#include <stdio.h>
#define null 0


void exch(int *m,int *n)
{

	int k;

    k=*m;
	*m=*n;
	*n=k;
//   printf("a=%d,b=%d\n",*m,*n);
}



int main(void)
{
	int a=1;
	int b=9;
	
	printf("a=%d,b=%d\n",a,b);
	exch(&a,&b);

	printf("a=%d,b=%d\n",a,b);



	return 0;
}
