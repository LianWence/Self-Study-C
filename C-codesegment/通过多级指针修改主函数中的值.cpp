/*
               2015.8.14  0:14
            ͨ���༶ָ��纯���޸�����������ͨ����i��ֵ 
*/
#include <stdio.h>
void g(int *);
void f(int **);
void h(int ***);

int main(void)
{
	int i = 6;
	
	printf("��ʼֵ��i = %d\n", i);
	g(&i);  //��ַ���� 
	
	return 0;
} 

void g(int *p)
{
	f(&p);
}

void f(int **q)
{
	h(&q);
}

void h(int ***s)
{
	***s = 10; // �ȼ���i = 10. 
	printf("���ս����i = %d\n", ***s);
}
