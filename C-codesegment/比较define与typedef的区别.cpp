//2016.3.23     10:57   测试typedef与define之间的区别 
#include <stdio.h>

#define int_ptr int *
typedef char* char_ptr; //typedef声明语句只能写在函数体外  且其默认最后一个字符串为新别名 不论中间有多少个字符串 

int main(void)
{
//	typedef (char *) char_ptr;  
	
	int a = 5;
	int_ptr p = &a;
	
	char b = 'A';
	char_ptr q = &b;
	
	printf("%d %c\n", *p, *q);  //输出字符的控制格式为%c  而不是%s字符串格式 
	
	return 0;
}
