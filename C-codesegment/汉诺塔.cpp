/*
                         2015.8.23   9:01
              �õݹ�˼������ŵ������        ������ȷ��� 
*/
#include <stdio.h>

void hannuota(int , char , char , char);

int main(void)
{
	char A, B, C;   //�Ƚ��������Ӷ������ 
	int n;      //������
	
	printf("������������:n = ");
	scanf("%d", &n);
	
	hannuota(n, 'A', 'B', 'C');  
	
	return 0; 
}

void hannuota(int n, char A , char B, char C)
{
	if (n == 1)
	{
		printf("����%d������ֱ�Ӵ�%c�ŵ�%c\n", n, A, C);
	}
	else
	{
		hannuota(n - 1, A, C, B);           //�Ƚ�A�����ϵ�n-1�����ӽ���C�ŵ�B������  �ܸ��� 
		printf("����%d������ֱ�Ӵ�%c�ŵ�%c\n", n, A, C);  //�ٽ���n�����Ӵ�Aֱ�ӷŵ�C������ 
		hannuota(n - 1, B, A, C);   //�µĿ�ʼ���ٽ���n-1�����Ӵ�B���ӽ���A�����Ƶ�C������  ����ܸ��ӣ����߼����Ѿ���� 
	}
}
