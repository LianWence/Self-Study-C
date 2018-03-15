//    2016.3.10      	10:22     测试一段代码的第一次执行的行为与以后执行的不同 
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
