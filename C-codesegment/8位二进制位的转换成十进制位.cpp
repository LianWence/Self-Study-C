/*
               2015.8.15  13:58
              求8位二进制位所对应的十进制数的范围 
*/
#include <stdio.h>
int main(void)
{
	char i = 0X80;  // 二进制形式为1000 0000; 定义成char字符型的目的：只保证输入一个字节，正好是8位二进制位 
	printf("%d", i);   //字符型的存储也是按照整型来存储的 
	
	return 0;
}
/*
    不难发现，将变量i定义成char类型，保证了i变量只能存储一个低8位的二进制补码
	如果要求一个负数二进制补码的的十进制数，先将其转化成十六进制数，然后再交给计算机就可以了。当然，正整数也可以这样做 
*/ 
