/*
           2015.8.14  18:26
       ð�����򷨣����ö༶ָ�� 
*/
#include <stdio.h>

void input(double *, int );
void order(double **, int );
void output(double *** ,int );

int main(void)
{
	double array[7];  //����һ���׵�ַΪarray������ 
	
	input(array, 7);  //array=&array[0]  ��Ϊ��ַ���� 
	
	return 0;
}

void input(double *pi, int length)  // �������Ĺ����ǶԽ��յ���������г�ʼ����ֵ 
{
	int i;
	
	printf("�����θ���Ԫ�ظ�ֵ��\n");
	for (i = 0; i < length; i++)
	{
		printf("array[%d] =  ", i);
		scanf("%lf", (pi +i));
	}
	order(&pi, length);   // ��ַ���ݣ����Եý�pi�ĵ�ַ���͹�ȥ��&pi 
}

void order(double **po,int extent) //�������Ĺ����ǣ��Խ��յ����������ð�ݷ����� 
{                                   //pi����������double*����po=&pi������poҪ����double*���ͱ����ĵ�ַ po���붨���double**po 
	int i, j, t;
	
	for (i = 0; i < extent - 1; i++)
	{
		for (j = i + 1; j < extent; j++)
		{
			if(*(*po + i) > *(*po + j) )
			    {
			    	t = *(*po + i);
			    	*(*po + i) = *(*po + j);
			    	*(*po + j) = t;
			    }
		}
	}
	output(&po, extent);
}

void output(double ***pt, int length)  //�������Ĺ����ǣ��Խ��յ������������� 

{
	int i;
	
	printf("�������Ԫ�ص�ֵΪ��\n");
	for (i = 0; i < length; i++)
	{
		printf("array[%d] = %8.2lf\t", length, *(**pt + i));  //
		if ((i + 1) % 3 == 0 )
		    printf("\n"); //ÿ��ֻ���3��Ԫ�� 
		
	}
}

