/*
       2015.8.29   22:37
      测试文件读写函数fputc()和fgetc()的用法 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char ah;
	char ch = 'm';
	
	if (fp = fopen("F:\\测试类文件\\a.txt", "w+")) //文件打开成功:函数返回该文件的地址；否则返回NULL 
	{
		printf("^_^文件打开成功!\n");
		
		if (fputc(ch, fp) == EOF) //文件读写函数原型:int fputc(int c, FILE *fp)  如果要插入字符，记得要加单引号‘’ 
		{                           //该函数如果被成功执行，返回值为c；否则为EOF（文件结束符） 
			printf("~_~代码写入失败!\n");       
			exit(0);
		}
		else
		{
			printf("^_^代码%c写入成功!\n", fputc(ch, fp));
			
			if ((ah = fgetc(fp)) != EOF)  //文件读写函数原型:int fgetc(FILE *fp) 该函数的功能是:从fp指向的文件中读取一个字节代码，再写入到该文件中 
			{                            //读取和写入成功之后，返回所读取的代码；否则，返回EOF（当读到文件结尾时，返回值相同） 
				printf("**** %c代码读取成功****\n", ah);
				
				if (fclose(fp))
				{
					printf("文件关闭失败！\n");
				}
				else
					printf("文件关闭成功!\n");
			}
			else
				printf("~_~读取失败\n");
		}
	}
	else
	{
		printf("文件打开失败");
		exit(0);
	}
	
	return 0;
}
/*
       fgetc()函数的功能是将从文件中读取的一字节代码再写入到文件中去 

*/
