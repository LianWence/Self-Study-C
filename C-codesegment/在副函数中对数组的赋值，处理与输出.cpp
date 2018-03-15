/*
                  2015.8.13   13:32
                通过两个副函数实现对主函数中的一组数组的赋值，处理和输出 
*/
#include <stdio.h>
void input(int *, int );
void output(int *, int );

int main()
{
	int a[9];
	
	input(a, 9);
	output(a, 9);
	
	return 0;
}

void input(int *p, int len)
{
	int i;

    printf("请依次给该数组赋值：\n"); 
	for (i = 0; i < len; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", (p +i)); //标准库函数scanf的实参必须为（p+i），否则赋值只对数组中的第一个元素起作用 
	} 
}

void output(int *q, int len)
{
	int j;
	
	printf("该数组各元素依次为：\n");
	for (j = 0; j < len; j++)
	{
		q[j] *= 2;   //  等价于*(q+i)  因为：指针变量q=指针常量a  所以两指针均指向同一存储空间（即内存编号相同） 
		printf("a[%d] = %d\t", j, q[j]);// 实参也可以写成*(q+j) 
	}
}
/*
       标准库函数scanf的实参也可以写成 【数组名+下标】的形式 ，等价于 【 &数组名[下标]】 
*/
