//2016.2.28  16:24  计算机日期升级版  
#include <stdio.h>
#include <time.h>   

int main()
{
	time_t biggest = 0x7FFFFFFF;  //time_t 是 long的typedef形式
	
	printf("biggest = %s \n", asctime(gmtime(&biggest)));	 //gmtime() 函数负责将参数转换成最大格林尼治(UTC)时间值  但是该函数不返回一个可打印的字符串 
															//asctime() 函数负责将获取 gmtime()函数 转换出的时间值 
	return 0;
}
