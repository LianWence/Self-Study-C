/*
                2015.8.14  9:10
             �纯��ʹ�ö�̬�ڴ� 
*/

#include <stdio.h>
#include <malloc.h>

void first(void);
void second(double **);
void third(double ***); 

int main()
{
	first();
	
	return 0;
}

 void first(void)
 {
 	double *p = (double *)malloc(sizeof(double));//������һ����������Ϊdouble�Ķ�̬��������ռ�ڴ���8���ֽڣ� 
 	second(&p);
 }
 
 void second(double **q)
 {
 	printf("����������һ��ʵ��:");
 	scanf("%lf", *q); //�˴�scanf������ʵ��Ҫ������pָ����Ǹ���̬�����ĵ�ַ������ָ�����p����p=*q�� 
 	third(&q);
 }
 
 void third(double ***s)
 {
 	printf("�ö�̬������ֵΪ��%lf\n", ***s);
 	free(**s);  //�ͷŵ��ö�̬�������ڴ棬ʵ��ֻҪ��ָ�����p��ȾͿ����ˡ�p=*q=**s�� 
 	printf("�ͷź�ö�̬������ֵΪ��%lf\n", ***s); //���***s = **q = *p = i;    ������߼����� 
 }
