//2016.3.23          11:43    测试副函数中的堆栈情况 
#include <stdio.h>

int * f(int )
{
	static int b = 10, c, a;
	int *p = &c;
	 
	c = a + b;
	
	return p;
} 
 
int main(void)
{
	int a = 5;
	
	printf("%d\n", f(a));  // 返回指针的调用是错误的,不论是副函数堆栈中的数据类型为static 只要调用完毕,该堆栈就被清空 ,返回的指针也是个垃圾指针 
	printf("%d\n", f(a));
	
	return 0;
} 

//副函数一旦被调用完毕,堆栈就会被清空,返回给主函数的指针也是个垃圾值,切勿这样乱调用 
