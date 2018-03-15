/*
           2015.8.14  10:57
         对结构体变量的赋值，初始化及输出 
*/
#include <stdio.h>

struct TV  //定义一个结构体名为TV的复合数据类型，由以下的多个基本变量组合而成 
{
	int price;
	float size;
	char color;
} ;

int main()
{
	struct TV store = {1000, 15.6, 'Y'};   //在定义结构体变量store的同时进行初始化 ,即可以整体赋值 
	
	struct TV store1;
	store1.price = 15000;
	store1.size = 17.3;
	store1.color = 'B';  //或者先定义，然后再对该结构体中的基本变量一一赋值，这种比较麻烦，不建议！ 
	
	printf("该TV的信息为：price = %d, size = %f, color = %c\n", store.price, store.size, store.color);
	printf("该TV的信息为：price = %d, size = %f, color = %c\n", store1.price, store1.size, store1.color);
	                       // 注意输出时，printf函数的实参必须为：该结构体中的基本类型变量，注意要书写正确 
	return 0;
}
