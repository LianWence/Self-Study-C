/*
        2015.8.29     23:58
     程序的功能是:从键盘输入字符，逐个存到磁盘中去，直到用户输入‘#’为止   
*/ 
#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
	FILE *fp; //保存文件的地址 
	char ch;
 	char *filename = "F:\\测试类文件\\test.txt"; 
	
	if ((fp = fopen(filename, "w")) == NULL) //函数执行成功，返回该文件的地址;否则返回NULL 
	{
		printf("~_~文件打开失败!\n");
		exit(0); //等价于return 0;   或者  return; 
	}
	
	printf("^_^文件打开成功,请输入字符串:");
	ch = getchar();
	
	while (ch != '#')   
	{
		fputc(ch, fp);  //将用户输入的字符串一一写入到制定文件中去 
		putchar(ch);  //将写入到文件中的代码打印到屏幕上 
		ch = getchar(); //由用户决定要不要继续对文件进行写入操作 
	}
	
	fclose(fp);   //关闭文件，防止数据丢失 
	
	return 0;
}
