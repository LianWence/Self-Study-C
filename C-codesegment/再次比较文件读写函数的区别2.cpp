/*
        2015.8.29   23:23
       再次比较文件读写函数和字符输入输出函数的区别 
*/
#include <stdio.h>

int main(void)
{
	char ch; 
	
	printf("****请连续输入两个字符:");
	
	ch = fgetc(stdin);   //stdin文件表示键盘设备文件，由系统自动控制其打开，读写和关闭的功能
	printf("fgetc函数的结果:%c\n", ch);
	
	ch = getchar();
	printf("getchar函数的结果:%c\n", ch);
	
	printf("fputc函数的结果:%c\n", fputc(ch, stdout));//stdout文件即显示器设备文件，同样由操作系统自动控制其打开，读写和关闭的功能 
	printf("putchar函数的结果:%c\n", putchar(ch));
	
	return 0;
}
/*
     标准设备文件:stdin键盘文件，stdout显示器文件，stderr错误输出文件均由操作系统控制 
*/
