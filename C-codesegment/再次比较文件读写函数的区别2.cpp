/*
        2015.8.29   23:23
       �ٴαȽ��ļ���д�������ַ������������������ 
*/
#include <stdio.h>

int main(void)
{
	char ch; 
	
	printf("****���������������ַ�:");
	
	ch = fgetc(stdin);   //stdin�ļ���ʾ�����豸�ļ�����ϵͳ�Զ�������򿪣���д�͹رյĹ���
	printf("fgetc�����Ľ��:%c\n", ch);
	
	ch = getchar();
	printf("getchar�����Ľ��:%c\n", ch);
	
	printf("fputc�����Ľ��:%c\n", fputc(ch, stdout));//stdout�ļ�����ʾ���豸�ļ���ͬ���ɲ���ϵͳ�Զ�������򿪣���д�͹رյĹ��� 
	printf("putchar�����Ľ��:%c\n", putchar(ch));
	
	return 0;
}
/*
     ��׼�豸�ļ�:stdin�����ļ���stdout��ʾ���ļ���stderr��������ļ����ɲ���ϵͳ���� 
*/
