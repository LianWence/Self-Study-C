/*
                2015.8.10  12:12
                ������continue�����÷����Լ�����scanf�����ķǿ��Ʒ��Ĵ��� 
*/
#include <stdio.h>
int main()
{
	char ch;
	
	int i;
	printf ("����������һ������i��");
	scanf ("%d", &i);
	printf ("i = %d\n", i);
	
	while ( (ch=getchar()) != '\n')
	      continue;   //ͨ��whileѭ������continue���ɹ��ؽ��û���i�ķǷ�������˵� 
	 
	int j;
	printf ("���ٴ���������һ������j��");
	scanf ("%d", &j);
	printf("j = %d\n", j);
	      
	return 0;
}
/*
    ע���׼�⺯��scanf�Ŀհ׷�������Ͷ����û����������ǿ��Ʒ��Ĵ��������� 
*/
