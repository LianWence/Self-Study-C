#include <stdio.h>
#include <stdlib.h>

#define Num 100
/*
	折半查找, 前提是该事物已经排好序 
*/
int binerySeach(int *array){

	int left = 0;
	int right = sizeof(array) / sizeof(int) - 1;
	int index = -1;
	int findData = 500;
	
	printf("right = %d\n", right);
	
	while(left <= right){
		
		int mid = (left + right) / 2;
		if(array[mid] == findData)
		{	
			index = mid;
			printf("index = %d\n", index);
			break;
		} 
		 else if(findData > array[mid])
		{
			left = mid + 1;		
		} 
		 else
		{
			right = mid - 1;
		}
		 
	}
	
	if(index != -1)
	{
		printf("find! index = %d\n", index);
	}
	 else 
	{
		printf("find NOT!");
	}
	return 0;
}


