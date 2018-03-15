/*
               2015.8.14  0:14
            通过多级指针跨函数修改主函数中普通变量i的值 
*/
#include <stdio.h>
void g(int *);
void f(int **);
void h(int ***);

int main(void)
{
	int i = 6;
	
	printf("初始值：i = %d\n", i);
	g(&i);  //地址传递 
	
	return 0;
} 

void g(int *p)
{
	f(&p);
}

void f(int **q)
{
	h(&q);
}

void h(int ***s)
{
	***s = 10; // 等价于i = 10. 
	printf("最终结果：i = %d\n", ***s);
}
