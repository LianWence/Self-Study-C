/*
            2015.8.30      11:11
   测试字符串如何用字符数组进行输出 
*/
#include <stdio.h>

int main(void)
{
	char ch[] = "hello";
	char ah[10] = "hello"; //事实上，该字符数组要占用6个字节，末尾还要加上字符‘\0’
	char bh[10] = {'h', 'e', 'l', '\0', 'l', '\0', 'o'}; 
	
	printf("ch = %s\n", ch);
	printf("ah = %s\n", ah); //遇到字符‘\0’时，结束输出
	
	printf("bh = %s\n", bh);  //"%s"字符串输出格式遇到'\0'时，会结束输出 
	
	printf("第二种情况输出结果为:bh = ");
	for (int i = 0; i < 10; i++)
		printf("%c", bh[i]);   //但是字符'\0'输出结果为字符a，为什么？？？？ 

    return 0;
}
