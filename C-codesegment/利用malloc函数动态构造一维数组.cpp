/*
               2015.8.13  22:50
         ����malloc��������һά��̬���� 
*/
#include <stdio.h>
#include <malloc.h>

void input(double *, int);
void output(double *, int);

int main()
{
	int len;
	double *Point;
	
	printf("����������Ҫ��Ԫ�ظ�����");
	scanf("%d", &len);
	
	Point = (double *)malloc(8 * len); //������ִ�У���ʾ�Ѿ������һά���� (�ȼ���Point[len])�Ĺ��� 
	input(Point, len);
	
	free(Point);
	
	return 0; 
}

void input(double *q, int number)
{
	int i;
	
	printf("�������θ���Ԫ�ظ�ֵ��\n");
	for (i = 0; i < number; i++)
	{
		printf("�븳ֵ��Point[%d] = ", i);
		scanf("%lf", (q + i));   // ʵ��Ҳ����д�� &q[i] 
	}
	output(q,  number);
}

void output(double *k, int much)
{
	int i, j;
	j = 0;
	
	printf("������ĸ���Ԫ�ص�ֵΪ��\n");
	for (i = 0; i < much; i++)
	{
		printf("Point[%d] = %lf\t", i, *(k + i));    //�ڶ���ʵ��Ҳ����д�� k[much]�ĸ�ʽ 
		j++;
		if(j % 2 == 0)
		    printf("\n");
	}
}
