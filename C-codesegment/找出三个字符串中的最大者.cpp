/*
         2015.8.30          13:14         
       �������������ַ����������е������ 
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[20], str[3][20];
	
	for (int i = 0; i < 3; i++)
	{
		printf("�������%d���ַ���:", i + 1);
		gets(str[i]);
	}   
	
	if (strcmp(str[0], str[1]) > 0)     //���ַ��ȽϺ����ǱȽ϶�Ӧλ�ϵİ�˹����ֵ�Ĵ�С�����ַ�������Ч�ֽ����޹� 
		strcpy(string, str[0]);
	else
		strcpy(string, str[1]);
	
	if (strcmp(str[2], string) > 0)
		strcpy(string, str[2]);
		
	printf("****�����ַ���:%s\n", string);
	
	return 0;
}
