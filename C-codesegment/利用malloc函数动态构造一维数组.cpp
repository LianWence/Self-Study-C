/*
               2015.8.13  22:50
         利用malloc函数构造一维动态数组 
*/
#include <stdio.h>
#include <malloc.h>

void input(double *, int);
void output(double *, int);

int main()
{
	int len;
	double *Point;
	
	printf("请输入您需要的元素个数：");
	scanf("%d", &len);
	
	Point = (double *)malloc(8 * len); //该语句的执行，表示已经完成了一维数组 (等价于Point[len])的构造 
	input(Point, len);
	
	free(Point);
	
	return 0; 
}

void input(double *q, int number)
{
	int i;
	
	printf("请您依次给各元素赋值：\n");
	for (i = 0; i < number; i++)
	{
		printf("请赋值：Point[%d] = ", i);
		scanf("%lf", (q + i));   // 实参也可以写成 &q[i] 
	}
	output(q,  number);
}

void output(double *k, int much)
{
	int i, j;
	j = 0;
	
	printf("该数组的各个元素的值为：\n");
	for (i = 0; i < much; i++)
	{
		printf("Point[%d] = %lf\t", i, *(k + i));    //第二个实参也可以写成 k[much]的格式 
		j++;
		if(j % 2 == 0)
		    printf("\n");
	}
}
