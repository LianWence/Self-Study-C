/*
                 2015.8.10  23:23
                 ���ö���ѭ��ʵ�ֶԶ�ά�������������� 
*/ 

#include <stdio.h>
int main(void)
{
	int a[3][4]; 
	int i, j;
	
	printf ("�밴Ҫ�����������Ԫ�ص�ֵ:\n");
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf ("\t");
            printf ("a[%d][%d] = ", i ,j );
			scanf ("%d", &a[i][j]);   //�ܹؼ�������   
	    }
		printf("\n");   
	}
	
	printf ("�ö�ά����Ϊ��\n");
	
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
             ���������ն�ά�������������������� 
*/ 
