/*
       2015.8.30     12:58
  统计用户输入的字符串中有多少个单词 
*/
#include <stdio.h>

int main(void)
{
	char str[100];
	int i;
	int num = 0, word = 0;
	char c;
	
	printf("****请输入一组字符串，以回车键结束:");
	gets(str);
	
	for (i = 0; (c = str[i]) != '\0'; i++)
	{
		if (c == ' ')   //当c为空白字符时，说明上一个单词正好结束。单词中的字母数要重置为零，开始下一个单词的统计 
			word = 0;
		else if(word == 0)
		{
			word = 1;  //避免对同一个单词重复计数 
			num++; 
		}
	}
	
	printf("该行中有%d个单词\n", num);
	
	return 0;
}
