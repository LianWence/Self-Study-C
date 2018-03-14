#include <stdio.h>

#define NUMBER_A 5
#define NUMBER_B 10
/*
	2018��1��30��01:27:08
	�鲢����
	    �ǽ����ڹ鲢�����ϵ�һ����Ч�������㷨, ���㷨�ǲ��÷��η���һ���ǳ�
	���͵�Ӧ��
		��������, ֻҪ�ӱȽ��������еĵ�һ����, ˭С����ȡ˭, ȡ�˺��±��Ƶ���һ������ȥ
		Ȼ���ٽ��бȽ�, ����ڼ�������Ϊ��, ��ֱ�ӽ���һ�����е���������ȡ������	 
		 
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
	printf("����\n"); 
	while(indexA < NUMBER_A)
	{
		c[indexC++] = a[indexA++];
	}
	
	while(indexB < NUMBER_B)
	{
		c[indexC++] = b[indexB++];
	}
	printf("����\n"); 
	int k;
	for(k = 0; k < NUMBER_A + NUMBER_B; k++)
	{
		printf("c[%2d] = %2d\n", k, c[k]);	
	}
	 
	return 0;
} 
