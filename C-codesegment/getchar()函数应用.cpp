/*
               2015.8.18  23:15
               测试getchar函数的用法，该函数适用于读取一段字符吧 
*/
#include <stdio.h>
int main(void)
{
	int i = 0;
	char ch;
	
	do
	{
		i++;
		printf("第%d次循环!!!\n", i);
		
		printf("按Y或y键继续\n");
	} while ((ch = getchar()) == 'Y' || (ch = getchar()) == 'y' ); // 还是不清楚getchar函数好像没有存储变量似得 
	
	return 0;
}
