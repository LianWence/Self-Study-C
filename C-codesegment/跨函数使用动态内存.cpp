/*
                2015.8.14  9:10
             跨函数使用动态内存 
*/

#include <stdio.h>
#include <malloc.h>

void first(void);
void second(double **);
void third(double ***); 

int main()
{
	first();
	
	return 0;
}

 void first(void)
 {
 	double *p = (double *)malloc(sizeof(double));//定义了一个数据类型为double的动态变量（所占内存是8个字节） 
 	second(&p);
 }
 
 void second(double **q)
 {
 	printf("请任意输入一个实数:");
 	scanf("%lf", *q); //此处scanf函数的实参要求是由p指向的那个动态变量的地址，就是指针变量p，而p=*q； 
 	third(&q);
 }
 
 void third(double ***s)
 {
 	printf("该动态变量的值为：%lf\n", ***s);
 	free(**s);  //释放掉该动态变量的内存，实参只要和指针变量p相等就可以了。p=*q=**s！ 
 	printf("释放后该动态变量的值为：%lf\n", ***s); //如此***s = **q = *p = i;    此语句逻辑错误 
 }
