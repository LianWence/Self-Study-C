#include <stdio.h>

#define NUMBER_A 5
#define NUMBER_B 10
/*
	2018年1月30日01:27:08
	归并排序
	    是建立在归并操作上的一种有效的排序算法, 该算法是采用分治法的一个非常
	典型的应用
		操作如下, 只要从比较两个数列的第一个数, 谁小就先取谁, 取了后下标移到下一个数上去
		然后再进行比较, 如果期间有数列为空, 那直接将另一个数列的数据依次取出即可	 
		 
*/ 
int main()
{
	int a[NUMBER_A] = {1, 3, 5, 7, 13};
	int b[NUMBER_B] = {2, 4, 6, 10, 12, 
					   14, 19, 22, 23, 25};
	
	int c[NUMBER_A + NUMBER_B];
	
	int indexA = 0;
	int indexB = 0;
	int indexC = 0;
	while(indexA < NUMBER_A && indexB < NUMBER_B)
	{
		if(a[indexA] < b[indexB])
		{
			c[indexC++] = a[indexA++];
		}
		else
		{
			c[indexC++] = b[indexB++];
		}
	} 
	printf("测试\n"); 
	while(indexA < NUMBER_A)
	{
		c[indexC++] = a[indexA++];
	}
	
	while(indexB < NUMBER_B)
	{
		c[indexC++] = b[indexB++];
	}
	printf("测试\n"); 
	int k;
	for(k = 0; k < NUMBER_A + NUMBER_B; k++)
	{
		printf("c[%2d] = %2d\n", k, c[k]);	
	}
	 
	return 0;
} 
