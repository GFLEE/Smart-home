/*************************************************************************
    > File Name: stu.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Tue 04 Sep 2018 11:16:27 PM PDT
 ************************************************************************/
#include <stdio.h>
#include <string.h>
struct student{

	char name[10];
	int num;
	char sex;
	int age;
	char *major;

}student;


int main(void)
{
	//char ch[10];
 strcpy(student.name,"lee");
 //student.name=ch;
 student.num=666;
 student.sex='m';
 student.age=20;
 student.major="CE";

 printf("name:%s\nnum:%d\nsex:%c\nage:%d\nmajor:%s\n",student.name,student.num,student.sex,student.age,student.major);




	return 0;
}
