/*
                2015.8.25          20:57
             用递归实现快速排序   
*/
#include <stdio.h>

#define len 10 

int * input_array(void);
int * quick_sort(int *, int, int);
int find_pos(int *, int, int);
void output_array(int *);

int main(void)
{
    input_array();	
	
	return 0;
}

int * input_array(void)
{
	int low, high;
	int a[len];
	
	low = 0;
	high = len - 1;
	
	printf("****请按要求任意输入:\n");
	for (int i = 0; i < len; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", (a + i));
	}
	
    //output_array(quick_sort(a, low, high));
}

int * quick_sort(int *a, int low, int high)
{
	int pos;
	
	if (low < high)
	{
		pos =  find_pos(a, low, high);  //找到第一个元素的位置 
		quick_sort(a, low, (pos - 1));   //再对左半部分进行快速排序 
		quick_sort(a, (pos + 1), high);   //再对右半部分进行快速排序 
	}
	
	return a;
}

int find_pos(int *a, int low, int high)  //找出元素的确切位置，一次只能找出一个 
{
	int val = a[low];  //默认先找到数组中第一个元素的准确地址 
	
	while (low < high)
	{
		while (low < high && a[high] <= val)
			high--;               //一旦执行循环 ，high指向的元素一直往左移 
		a[low] = a[high];         //再把小的值传到左边 
		while (low < high && a[low] >= val)    
		    low++;                //一旦执行循环 ，low指向的元素一直往右移 
		a[high] = a[low];
	}
	a[low] = val;   //这个确切位置应该保存第一个元素的值 
    
    return low;
}

void output_array(int *a)
{
	printf("****快速排序之后的结果为^-^:\n");
	for (int i = 0; i < len; i++)
	{
		printf("a[%d] = %d\t", i, a[i]);
		if ((i + 1) % 3 == 0)
		printf("\n");
	}
	
	return;
}
