//2016.3.9    10:44       
#include <stdio.h>
#include <string.h>

int main(void)
{
	char test[10] = "str";
	int x;
	
	x = strlen(test);  //strlen��������"\0" ��������ַ� 
	printf("���ַ����ĳ�������ֵΪ:%d\n", x);
	printf("���ַ�����ʵ�ʳ���Ϊ:%d\n", (x + 1));
	
	return 0;
}
