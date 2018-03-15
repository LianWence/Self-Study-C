/*
           2015.8.14  12:06
        如何从结构体变量中取出一个成员的信息 
*/
#include <stdio.h>

struct student
{
	int age;
	float score;
	double height;
};   

int main()
{
	struct student doubi;  //定义一个结构体变量doubi,成员名分别为三个基本变量 
	struct student *point = &doubi;  //指针变量point保存了数据类型为struct student变量doubi的地址，即*point=doubi 
	
	point->height = 178.56;  //在计算机内部会被转化成（*point）.height,等价于doubi.height  
	point->score = 89.5;  //原因同上 
	doubi.age = 21;
	
	printf("该学生的信息为:height = %lf, score = %f, age = %d", point->height, doubi.score, point->age); 
	
	
	return 0;
}
