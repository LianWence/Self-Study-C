#include <stdio.h>
#include <string.h>

int main(void)
{
	char destination[25];
	char a[] = "����", b[] = "����", c[] = "С�ձ�!";
	
	strcpy(destination, a);   //�ַ�������������ʽ:strcpy(�ַ�������1,�ַ�������2)  �����ַ�������2Ϊֱ��д���ַ���Ҳ���� 
	strcat(destination, b);//�ַ������Ӻ�����ʽ��strcat(�ַ�������1���ַ�������2)   
	strcat(destination, c); //���ߺ���ִ����Ϻ󣬾��Ὣ����ϳɵ��ַ�������1���׵�ַ���� 
	
	printf("****�����������Ա�:****\n"); 
	puts(destination);  //�ַ���������������Ϻ��Զ����� 
	printf("%s\n", destination);
	
	return 0;
}
