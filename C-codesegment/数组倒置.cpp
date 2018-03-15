/*
                  2015.8.10  22:38
                  功能：实现对用户输入的数组进行倒置 
*/ 

#include <stdio.h>
int main()
{
	int a[8]; 
	int i, j;
	int t;
	
	printf ("请按要求依次输入该数组各元素的值：\n");
	for (i = 0; i < 8 ; i++)
	{
	   printf ("请输入：a[%d] = ", i);
	   scanf ("%d", &a[i]);
    }
    
	i = 0;  //不能缺少，否则会退出下面的while循环，将数组按原样输出！！！！ 
	j = 7;
	while (i < j)    
	{
		t = a[i];           
		a[i] = a[j];
		a[j] = t;           //保证了该数组中第一个元素同最后一个元素进行交换数值，循环结构保证了对应位置的数值的交换!! 
		
		i++;
		j--;	
	}
	for (i = 0; i < 8 ; i++)
	    printf ("a[%d] = %d\n", i, a[i]);
	
	return 0;
}
