/*
                  2015.8.13  21:42
            ѧϰmalloc�������÷��Լ�ͨ����ַ�����ڸ������ж��������ı������и�ֵ��������ߴ��� 
*/
#include <stdio.h>
#include <malloc.h>

void input(float *);
void output(float *);

int main()
{
	float *p = (float *)malloc(sizeof(float));  
	
	input(p);
	output(p);
	
	free(p);   //�ͷŵ�ָ��p��ָ����ǿ鶯̬�ڴ�洢 
	printf("�ͷŵ���̬�ڴ�洢����֮��ñ�����ֵ��  %f\n", *p);  //*p�Ѿ������ڲ����ڱ�������ڴ�洢���������ǷǷ��� 
	
	return 0;
}

void input(float *q) //�������Ĺ����ǣ����������е��Ǹ�����4�ֽڶ�̬�洢����ı������и�ֵ 
{
	printf("������:*p = ");
	scanf("%f", q);  // q = p ��Ϊ��ַ���� 
}

void output(float *q)  //�������Ĺ����ǣ�����������е��Ǹ���̬�洢������ֵ 
{
	printf("�ö�̬�ڴ�洢������ֵΪ��%f\n", *q); //*q = *p   ͬ������Ϊ��ַ���� 
}
