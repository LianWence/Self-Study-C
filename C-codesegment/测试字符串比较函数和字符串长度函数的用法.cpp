/*
      2015.8.30      12:33
    测试字符串函数strlen()和strcmp()函数的用法 
*/ 
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[] = "Hello!", str2[] = "How are you?", str[25];
	int len1, len2, len3;
	
	len1 = strlen(str1);
	len2 = strlen(str2);
	
	if(strcmp(str1, str2) > 0)  //该函数会有返回值，若str1>str2,返回值为正整数，相等则返回0，小于则返回负整数 
	{
		strcpy(str, str1);
		strcat(str, str2);
	}
	else if(strcmp(str1,str2) < 0)
	{
		strcpy(str, str2);
		strcat(str, str1);
	}
	else
		strcpy(str, str1);
		
	len3 = strlen(str);     //该函数返回str字符串的有效长度，不包括字符'\0',若遇到该字符时，函数就会停止执行 
	
	puts(str);
	printf("len1 = %d, len2 = %d, len3 = %d\n", len1, len2, len3);
	
	return 0;
}
