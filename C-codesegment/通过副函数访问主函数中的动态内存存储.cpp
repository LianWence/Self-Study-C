/*
                  2015.8.13  21:42
            学习malloc函数的用法以及通过地址传递在副函数中对主函数的变量进行赋值，输出或者处理 
*/
#include <stdio.h>
#include <malloc.h>

void input(float *);
void output(float *);

int main()
{
	float *p = (float *)malloc(sizeof(float));  
	
	input(p);
	output(p);
	
	free(p);   //释放掉指针p所指向的那块动态内存存储 
	printf("释放掉动态内存存储区域之后该变量的值：  %f\n", *p);  //*p已经不属于不属于本程序的内存存储，这样做是非法的 
	
	return 0;
}

void input(float *q) //本函数的功能是：对主函数中的那个含有4字节动态存储区域的变量进行赋值 
{
	printf("请输入:*p = ");
	scanf("%f", q);  // q = p 因为地址传递 
}

void output(float *q)  //本函数的功能是：输出主函数中的那个动态存储变量的值 
{
	printf("该动态内存存储变量的值为：%f\n", *q); //*q = *p   同样是因为地址传递 
}
