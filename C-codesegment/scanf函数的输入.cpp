/*
                2015.8.10  12:12
                检验了continue语句的用法，以及对于scanf函数的非控制符的处理 
*/
#include <stdio.h>
int main()
{
	char ch;
	
	int i;
	printf ("请任意输入一个整数i：");
	scanf ("%d", &i);
	printf ("i = %d\n", i);
	
	while ( (ch=getchar()) != '\n')
	      continue;   //通过while循环搭配continue语句成功地将用户对i的非法输入过滤掉 
	 
	int j;
	printf ("请再次任意输入一个整数j：");
	scanf ("%d", &j);
	printf("j = %d\n", j);
	      
	return 0;
}
/*
    注意标准库函数scanf的空白符的问题和对于用户输入垃圾非控制符的处理！！！！ 
*/
