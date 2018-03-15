/*
         2015.8.30          13:14         
       任意输入三个字符串，求其中的最大者 
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[20], str[3][20];
	
	for (int i = 0; i < 3; i++)
	{
		printf("请输入第%d个字符串:", i + 1);
		gets(str[i]);
	}   
	
	if (strcmp(str[0], str[1]) > 0)     //该字符比较函数是比较对应位上的阿斯科马值的大小，跟字符串的有效字节数无关 
		strcpy(string, str[0]);
	else
		strcpy(string, str[1]);
	
	if (strcmp(str[2], string) > 0)
		strcpy(string, str[2]);
		
	printf("****最大的字符串:%s\n", string);
	
	return 0;
}
