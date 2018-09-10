#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{

int fd=open("./test.txt",O_RDWR);
//printf("%d",fd);

if(fd==-1)
{
	printf("Oen file failed!");
	return -1;
}

char buf[5] = "12345";
write(fd,buf,5);
char buf2[5]="abcde";
write(fd,buf2,5);
printf("write finished!\n");

//close(fd);

lseek(fd,-5,SEEK_CUR);


//fd=open("./test.txt",O_RDWR);

char r_buf[5]={0};

read(fd,r_buf,5);

printf("r_buf is %s\n",r_buf);






return 0;

}

