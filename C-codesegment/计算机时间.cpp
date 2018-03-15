//2016.2.28   16:13   编程实现计算机的日期 
#include <stdio.h>
#include <time.h>  //不可缺少的头文件 

int main()
{
	//time_t biggest = 0x7FFFFFFF;   //在C语言中time_t  是 long的typedef形式 
	long biggest = 0x7FFFFFFF; 
	
	printf("biggest = %s \n", ctime(&biggest));  //ctime()  函数负责将十六进制参数转换成当地时间   此处指加利福尼亚 
	return 0;
} 
