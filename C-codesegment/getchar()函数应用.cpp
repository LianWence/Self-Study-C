/*
               2015.8.18  23:15
               ����getchar�������÷����ú��������ڶ�ȡһ���ַ��� 
*/
#include <stdio.h>
int main(void)
{
	int i = 0;
	char ch;
	
	do
	{
		i++;
		printf("��%d��ѭ��!!!\n", i);
		
		printf("��Y��y������\n");
	} while ((ch = getchar()) == 'Y' || (ch = getchar()) == 'y' ); // ���ǲ����getchar��������û�д洢�����Ƶ� 
	
	return 0;
}
