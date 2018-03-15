/*
        2015.8.30         11:33 
       测试字符串数组的输入与输出函数的用法 
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	char ch[50];
	
	printf("请任意输入一组字符串，以回车键结束:");
	gets(ch); //字符串输入函数,从键盘输入一组以回车符为结束的数组。格式getc(字符数组名) 
	puts(ch);//字符串输出函数，将字符串显示到屏幕上，完成后，自动换行 
	
	return 0;
}
