//2016.3.9    10:44       
#include <stdio.h>
#include <string.h>

int main(void)
{
	char test[10] = "str";
	int x;
	
	x = strlen(test);  //strlen并不考虑"\0" 这个隐含字符 
	printf("该字符串的长度理论值为:%d\n", x);
	printf("该字符串的实际长度为:%d\n", (x + 1));
	
	return 0;
}
