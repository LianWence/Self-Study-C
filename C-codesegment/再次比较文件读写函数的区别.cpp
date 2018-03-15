/*
            2015.8.29   23:14
         比较文件读写函数与字符读写函数的区别 
*/ 
#include <stdio.h>

int main(void)
{
	char ch, sh; 
	
	printf("****请连续输入两个字符:");
	
	ch = fgetc(stdin);   //stdin文件表示键盘设备文件，由系统自动控制其打开，读写和关闭的功能
	printf("fgetc函数的结果:%c\n", ch);
	
	printf("putchar函数的结果:%c\n", putchar(ch)); 
	
	sh = getchar();
	printf("getchar函数的结果:%c\n", sh);
	
	printf("fputc函数的结果:%c\n", fputc(sh, stdout));//stdout文件即显示器设备文件，同样由操作系统自动控制其打开，读写和关闭的功能 
	
	
	return 0;
}
/*
   不难发现:1.  fgetc(stdin)函数等价于getchar()，且从键盘读入各种字符，但不能输出 
            2.  fputc(c,stdout)函数等价于putchar(c),将各种字符写入到文件中，只是无法在显示器文件中显示空白符，回车符以及结束符 
            3.  这些函数默认一次只能读写一个字节的字符 
*/
