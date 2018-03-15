/*
      2015.8.30         0:26
      将指定的文件内容读取出来，直至文件内容结束 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char ch;
	char *filename = "F:\\测试类文件\\test.txt";
	
	if ((fp = fopen(filename, "r")) == NULL)    //w的文件打开方式是覆盖原有的文件，并创建出一个新的空文本文件 ，此处只能为r 
	{
		printf("~_~文件打开失败!\n");
		exit(0);  //等价于return 0； 或者 return； 
	}
	
	ch = fgetc(fp);  //将从该文件中读取的代码字符存放到变量CH中，以供while循环判断
	while (ch != EOF)
	{
		putchar(ch);  //将该文件的内容一个一个字节进行输出
		ch = fgetc(fp); //将该文件中下一个字节读入进来，再次进行判断 
	} 
	
	fclose(fp);
	
	return 0;
}
