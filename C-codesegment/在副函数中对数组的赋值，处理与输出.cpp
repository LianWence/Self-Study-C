/*
                  2015.8.13   13:32
                ͨ������������ʵ�ֶ��������е�һ������ĸ�ֵ���������� 
*/
#include <stdio.h>
void input(int *, int );
void output(int *, int );

int main()
{
	int a[9];
	
	input(a, 9);
	output(a, 9);
	
	return 0;
}

void input(int *p, int len)
{
	int i;

    printf("�����θ������鸳ֵ��\n"); 
	for (i = 0; i < len; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", (p +i)); //��׼�⺯��scanf��ʵ�α���Ϊ��p+i��������ֵֻ�������еĵ�һ��Ԫ�������� 
	} 
}

void output(int *q, int len)
{
	int j;
	
	printf("�������Ԫ������Ϊ��\n");
	for (j = 0; j < len; j++)
	{
		q[j] *= 2;   //  �ȼ���*(q+i)  ��Ϊ��ָ�����q=ָ�볣��a  ������ָ���ָ��ͬһ�洢�ռ䣨���ڴ�����ͬ�� 
		printf("a[%d] = %d\t", j, q[j]);// ʵ��Ҳ����д��*(q+j) 
	}
}
/*
       ��׼�⺯��scanf��ʵ��Ҳ����д�� ��������+�±꡿����ʽ ���ȼ��� �� &������[�±�]�� 
*/
