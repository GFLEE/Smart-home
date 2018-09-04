/*************************************************************************
	> File Name: mul.c
	> Author: csgec
	> Mail: csgec@163.com 
	> Created Time: Mon 03 Sep 2018 08:09:22 PM PDT
 ************************************************************************/

#include <stdio.h>
int main()
{

  int i=1;
  int j=1;



	for(i=1;i<=9;i++)
	{
	
		 for(j=1;j<=i;j++)
		 {

			
		    printf("%d*%d=%d\t",i,j,i*j);
			

		 }
	printf("\n");
	}



	return 0;


}




