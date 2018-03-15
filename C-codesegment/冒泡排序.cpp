/*
           2015.8.14  18:26
       冒泡排序法，采用多级指针 
*/
#include <stdio.h>

void input(double *, int );
void order(double **, int );
void output(double *** ,int );

int main(void)
{
	double array[7];  //定义一个首地址为array的数组 
	
	input(array, 7);  //array=&array[0]  均为地址传递 
	
	return 0;
}

void input(double *pi, int length)  // 本函数的功能是对接收到的数组进行初始化赋值 
{
	int i;
	
	printf("请依次给各元素赋值：\n");
	for (i = 0; i < length; i++)
	{
		printf("array[%d] =  ", i);
		scanf("%lf", (pi +i));
	}
	order(&pi, length);   // 地址传递，所以得将pi的地址发送过去即&pi 
}

void order(double **po,int extent) //本函数的功能是：对接收到的数组进行冒泡法排序 
{                                   //pi数据类型是double*由于po=&pi，所以po要保存double*类型变量的地址 po必须定义成double**po 
	int i, j, t;
	
	for (i = 0; i < extent - 1; i++)
	{
		for (j = i + 1; j < extent; j++)
		{
			if(*(*po + i) > *(*po + j) )
			    {
			    	t = *(*po + i);
			    	*(*po + i) = *(*po + j);
			    	*(*po + j) = t;
			    }
		}
	}
	output(&po, extent);
}

void output(double ***pt, int length)  //本函数的功能是：对接收到的数组进行输出 

{
	int i;
	
	printf("该数组各元素的值为：\n");
	for (i = 0; i < length; i++)
	{
		printf("array[%d] = %8.2lf\t", length, *(**pt + i));  //
		if ((i + 1) % 3 == 0 )
		    printf("\n"); //每行只输出3个元素 
		
	}
}

