#include<stdio.h>
#include<stdlib.h>

#define Num 200
/*
	����ѡ������ĸĽ���ʩ, ֻ�Ƚϲ�����,һ��ֻ����һ�� 
*/

int mainTest(){
	int array[Num]; 
	int i;
	
	for(i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		array[i] = rand() % 1000;
	}
	
	int j;
	for(j = 0; j < Num - 1; j++)
	{
		int minIndex = j;
		int k;
		for(k = j + 1; k < Num; k++)
		{
			if(array[minIndex] > array[k])
			{
				minIndex = k;
			}
		}
		
		if(minIndex != j)
		{
			array[minIndex] ^= array[j];
			array[j] ^= array[minIndex];
			array[minIndex] ^= array[j];
		}
		
	} 
	for(i = 0; i < Num; i++)
	{
		printf("array[%3d] = %3d\n", i, *(array + i));
	}
	
//	binerySeach(array);
	printf("++++++++++++++++++++++\n");
	printChecker();
	
	
	printf("++++++++++++++++++++++\n");
//	printf("��֤�鲢����\n");
//	mergeSort();
	 
	return 0; 
} 
