//2016.3.23     10:57   ����typedef��define֮������� 
#include <stdio.h>

#define int_ptr int *
typedef char* char_ptr; //typedef�������ֻ��д�ں�������  ����Ĭ�����һ���ַ���Ϊ�±��� �����м��ж��ٸ��ַ��� 

int main(void)
{
//	typedef (char *) char_ptr;  
	
	int a = 5;
	int_ptr p = &a;
	
	char b = 'A';
	char_ptr q = &b;
	
	printf("%d %c\n", *p, *q);  //����ַ��Ŀ��Ƹ�ʽΪ%c  ������%s�ַ�����ʽ 
	
	return 0;
}
