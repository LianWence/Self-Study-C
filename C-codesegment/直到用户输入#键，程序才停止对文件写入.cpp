/*
        2015.8.29     23:58
     ����Ĺ�����:�Ӽ��������ַ�������浽������ȥ��ֱ���û����롮#��Ϊֹ   
*/ 
#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
	FILE *fp; //�����ļ��ĵ�ַ 
	char ch;
 	char *filename = "F:\\�������ļ�\\test.txt"; 
	
	if ((fp = fopen(filename, "w")) == NULL) //����ִ�гɹ������ظ��ļ��ĵ�ַ;���򷵻�NULL 
	{
		printf("~_~�ļ���ʧ��!\n");
		exit(0); //�ȼ���return 0;   ����  return; 
	}
	
	printf("^_^�ļ��򿪳ɹ�,�������ַ���:");
	ch = getchar();
	
	while (ch != '#')   
	{
		fputc(ch, fp);  //���û�������ַ���һһд�뵽�ƶ��ļ���ȥ 
		putchar(ch);  //��д�뵽�ļ��еĴ����ӡ����Ļ�� 
		ch = getchar(); //���û�����Ҫ��Ҫ�������ļ�����д����� 
	}
	
	fclose(fp);   //�ر��ļ�����ֹ���ݶ�ʧ 
	
	return 0;
}
