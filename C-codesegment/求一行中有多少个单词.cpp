/*
       2015.8.30     12:58
  ͳ���û�������ַ������ж��ٸ����� 
*/
#include <stdio.h>

int main(void)
{
	char str[100];
	int i;
	int num = 0, word = 0;
	char c;
	
	printf("****������һ���ַ������Իس�������:");
	gets(str);
	
	for (i = 0; (c = str[i]) != '\0'; i++)
	{
		if (c == ' ')   //��cΪ�հ��ַ�ʱ��˵����һ���������ý����������е���ĸ��Ҫ����Ϊ�㣬��ʼ��һ�����ʵ�ͳ�� 
			word = 0;
		else if(word == 0)
		{
			word = 1;  //�����ͬһ�������ظ����� 
			num++; 
		}
	}
	
	printf("��������%d������\n", num);
	
	return 0;
}
