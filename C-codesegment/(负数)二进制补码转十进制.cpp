/*
              2015.8.15  12:07
        二进制补码转十进制数 ，通过十六进制位作为桥梁 
*/
#include <stdio.h>
int main(void)
{
    int i;
    
	printf("请输入该负数补码所对应的的十六进制形式(8位)：");//补码最高位为1时，表示该数为负数
	                                           // 负数的十六进制：是由其32位补码直接转化成十六进制位而得到的 
    scanf("%x", &i); //以十六进制的格式输入 如果该数为负数，则要输入完整的8位或者16位的十六进制数 否则系统默认为正数 
	
	printf("该数的十进制形式为：%d\n", i);
	printf("该数的十六进制位：%#x\n", i); 
	
	return 0;
}
/*
    在计算机中，对于正整数的存储：十进制数 ===二进制补码===十六进制数  
	 但是负整数数则例外，负整数的二进制补码和该数的十六进制位是直接等价互换的，求取十进制数，则要先对补码进行
 取反，并加一，才将二进制位直接转化成十进制数。
     一个十六进制数的最高位为A到F任意一个时，则该数为负数，不可以直接转化成十进制数。
	 在计算机中，输入十六进制数时，如果输入的数位数不够，则默认左边一一补零。同十进制数的输入一样  如果要输入十六进制
  负数时必须该数的高位用f数补满
     不论是正整数还是负整数，该数的十六进制形式跟二进制补码形式是可以直接互换的。	  
*/
