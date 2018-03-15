/*
                 2015.8.10  23:23
                 利用多重循环实现对二维数组的输入与输出 
*/ 

#include <stdio.h>
int main(void)
{
	int a[3][4]; 
	int i, j;
	
	printf ("请按要求依次输入各元素的值:\n");
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf ("\t");
            printf ("a[%d][%d] = ", i ,j );
			scanf ("%d", &a[i][j]);   //很关键的输入   
	    }
		printf("\n");   
	}
	
	printf ("该二维数组为：\n");
	
	for (i = 0; i < 3 ; i++)
	{
		for (j = 0; j < 4; j++)
	    {
	        printf ("a[%d][%d] = %d", i, j, a[i][j]);
	        printf ("\t");
	    } 
		printf("\n");  
		 
	}
	return 0;
}
/*
             任务是掌握二维数组的输入与输出！！！ 
*/ 
