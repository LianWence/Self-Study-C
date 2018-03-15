#include <stdio.h>
#include <string.h>

int main(void)
{
	char destination[25];
	char a[] = "老子", b[] = "灭了", c[] = "小日本!";
	
	strcpy(destination, a);   //字符串拷贝函数格式:strcpy(字符数组名1,字符数组名2)  或者字符数组名2为直接写成字符串也可以 
	strcat(destination, b);//字符串连接函数格式：strcat(字符数组名1，字符数组名2)   
	strcat(destination, c); //两者函数执行完毕后，均会将新组合成的字符数组名1的首地址返回 
	
	printf("****两种输出结果对比:****\n"); 
	puts(destination);  //字符串输出函数输出完毕后，自动换行 
	printf("%s\n", destination);
	
	return 0;
}
