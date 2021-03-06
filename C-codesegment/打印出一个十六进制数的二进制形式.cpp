/*
         2015.8.30      9:55
      将一个十六进制的数用二进制形式打印出来   
*/
#include <stdio.h>

int main(void)
{
	int i;
	long a;
	
	printf("****请输入一个十六进制数:");
	scanf("%X", &a); //以十六进制形式读入 
	
	printf("该数的二进制形式为:\n");
	for(i = 31; i >= 0; i--)     //通过该循环将每位的二进制位进行输出 
		printf("%ld", (a & 1 << i ? 1 : 0));  //<<和>> 的运算符优先级高于&  a & 1的目的将整型数a低位的二进制位进行输出 
	                           //1<<i的目的保证每次将各个二进制位的数进行有序输出，按从高位到最低位输出。i从31（即第32位）自减到0（最低位） 
	return 0;
}
