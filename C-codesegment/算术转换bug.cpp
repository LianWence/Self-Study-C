//  2016.3.9    10:28    测试C语言中的类型转换的BUG 

#include <stdio.h>
#include <string.h>

int array[] = {23, 34, 12, 17, 204, 99, 16};
#define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))  //sizeof函数  默认返回值为无符号类型----unsigned int类型 

int main(void)
{
	int d = -1; 
	int x;

	if (d <= (int)(TOTAL_ELEMENTS - 2))	  //可以手动强制类型转换 告诉编译器要转换成省么类型的数据 
//	if (d <= (TOTAL_ELEMENTS - 2)) //d = -1的值被编译器由整型转换为无符号类型,-1会被转换成一个很大的正数  则判断条件为假 
	{	
		printf("####理论值:23\n");
		x = array[d + 1];
		printf("****实际值: %d\n", x); 
	}
	else
		printf("类型转换出错!\n");
	return 0;
}

//  切记不要滥用,乱用无符号类型的数据,避免增加不必要的复杂性 
