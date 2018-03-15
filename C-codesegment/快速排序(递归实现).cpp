/*
                2015.8.25          20:57
             �õݹ�ʵ�ֿ�������   
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
	
	printf("****�밴Ҫ����������:\n");
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
		pos =  find_pos(a, low, high);  //�ҵ���һ��Ԫ�ص�λ�� 
		quick_sort(a, low, (pos - 1));   //�ٶ���벿�ֽ��п������� 
		quick_sort(a, (pos + 1), high);   //�ٶ��Ұ벿�ֽ��п������� 
	}
	
	return a;
}

int find_pos(int *a, int low, int high)  //�ҳ�Ԫ�ص�ȷ��λ�ã�һ��ֻ���ҳ�һ�� 
{
	int val = a[low];  //Ĭ�����ҵ������е�һ��Ԫ�ص�׼ȷ��ַ 
	
	while (low < high)
	{
		while (low < high && a[high] <= val)
			high--;               //һ��ִ��ѭ�� ��highָ���Ԫ��һֱ������ 
		a[low] = a[high];         //�ٰ�С��ֵ������� 
		while (low < high && a[low] >= val)    
		    low++;                //һ��ִ��ѭ�� ��lowָ���Ԫ��һֱ������ 
		a[high] = a[low];
	}
	a[low] = val;   //���ȷ��λ��Ӧ�ñ����һ��Ԫ�ص�ֵ 
    
    return low;
}

void output_array(int *a)
{
	printf("****��������֮��Ľ��Ϊ^-^:\n");
	for (int i = 0; i < len; i++)
	{
		printf("a[%d] = %d\t", i, a[i]);
		if ((i + 1) % 3 == 0)
		printf("\n");
	}
	
	return;
}
