#include <stdio.h>
#include <stdlib.h>
/*
	��ӡ10 X 10������ ,���������10ö���ӵ�λ�� 
*/
int printChecker()
{
	int j;
	int k;
	
	int array[10][10] = {0};
	for(j = 0; j < 10; j++)
	{
		int row = rand() % 10;
		int col = rand() % 10;
		
		if(array[row][col] == 0)
		{
			array[row][col] = 1;
			continue;
		}
		
		j--;
	} 
	
	for(j = 0; j < 10; j++)
	{
		for(k = 0; k < 10; k++)
		{ 
			if(array[j][k] == 1)
			{
				printf("X  ");
				continue;
			}
			printf("*  ");
		}
		putchar(10);
	} 
	
	return 0;
}
