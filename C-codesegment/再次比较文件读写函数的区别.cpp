/*
            2015.8.29   23:14
         �Ƚ��ļ���д�������ַ���д���������� 
*/ 
#include <stdio.h>

int main(void)
{
	char ch, sh; 
	
	printf("****���������������ַ�:");
	
	ch = fgetc(stdin);   //stdin�ļ���ʾ�����豸�ļ�����ϵͳ�Զ�������򿪣���д�͹رյĹ���
	printf("fgetc�����Ľ��:%c\n", ch);
	
	printf("putchar�����Ľ��:%c\n", putchar(ch)); 
	
	sh = getchar();
	printf("getchar�����Ľ��:%c\n", sh);
	
	printf("fputc�����Ľ��:%c\n", fputc(sh, stdout));//stdout�ļ�����ʾ���豸�ļ���ͬ���ɲ���ϵͳ�Զ�������򿪣���д�͹رյĹ��� 
	
	
	return 0;
}
/*
   ���ѷ���:1.  fgetc(stdin)�����ȼ���getchar()���ҴӼ��̶�������ַ������������ 
            2.  fputc(c,stdout)�����ȼ���putchar(c),�������ַ�д�뵽�ļ��У�ֻ���޷�����ʾ���ļ�����ʾ�հ׷����س����Լ������� 
            3.  ��Щ����Ĭ��һ��ֻ�ܶ�дһ���ֽڵ��ַ� 
*/
