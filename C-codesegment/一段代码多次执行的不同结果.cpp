//    2016.3.10      	10:22     ����һ�δ���ĵ�һ��ִ�е���Ϊ���Ժ�ִ�еĲ�ͬ 
#include <stdio.h>

int main(void)
{
	static char a = ' ';
	char string[10] = "fuck you";
	
	printf("%c %s \n", a, string);
	
	a = ',';
	printf("%c %s \n", a, string);
	
	return 0;
}
