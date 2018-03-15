/*
                    2015.8.29        20:55
            测试文件打开函数和文件关闭函数的用法        
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;  //FILE的数据类型已经在头文件中定义好了 
	
	if (fp = fopen("F:\\测试类文件\\test1.bat", "r+"))  //文件名完整且路径也得完整  "r+"打开一个文件可读可写 
	{                                            //文件打开函数fopen()带有返回值，打开文件成功则返回该文件的地址，否则返回NULL 
		printf("****打开文件成功!****\n");            //该函数的原型:FILE * fopen(“文件完整名+完整路径”, “文件打开方式”) 
	}
	else
	{
		printf("****打开文件失败!****\n");
		exit(0);
	}
	
	if (fclose(fp))	  //文件关闭函数的原型:int fclose(FILE *fp)  当该函数成功执行时，会返回0；否则，会返回非零数 
	{                        //该函数的形参为地址类型，数据类型为FILE * 
		printf("++++文件关闭失败!++++\n");
	}
	{
		printf("++++文件关闭成功!++++\n");
	}
}
