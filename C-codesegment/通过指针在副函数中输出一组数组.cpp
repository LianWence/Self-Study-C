/*
         2015.8.13  12:35
       通过副函数输出一组数组（定义指针为形参来实现） 
*/

#include <stdio.h>
void output(int *, int );

int main()
{
	int a[6];
	int i;
	
	printf("请依次给数组的各个元素赋值：\n");
	for (i = 0; i < 6; i++)
	{
		printf("a[%d]= ", i);
		scanf("%d", (a + i)); //数组名a即指针常量，且a指向a[0]，所以该数组各个元素的地址为（a+i），等价于&a[i]。 
	}
	
	output(a, 6);  //实参必须为数组地址（即数组名）和数组个数，由此可以副函数可以确定一个数组 
	
	return 0;
}

void output(int *p, int len)  //本函数的功能是：将在主函数输入的数组输出！  指针变量p接收数组地址，普通变量接收数组个数 
{
	int i;
	
	printf("该数组中各个元素的值为：\n");
	for (i = 0; i < len; i++)
	    printf("a[%d] = %d\t", i, *(p + i));  
}

