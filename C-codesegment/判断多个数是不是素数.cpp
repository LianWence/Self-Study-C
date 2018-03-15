/*
                         2015.8.11  12:57
                 合理设计副函数来解决求出2到某个数之间的所有的素数！！！ 
*/
#include <stdio.h>

bool IsPrime(int i);   //函数声明又叫函数原型，它是一个语句，所以后面必须跟上分号“；”！！！！ 

int main()

{
	int val;
	int i, j;
	
	j = 0;
	
	printf("请输入您想判断的最大数的边界值：");
	scanf("%d", &val);
	
	printf("2到%d之间是素数的为：\n", val);
	
	for (i = 2; i < val; i++)
	{
		if (IsPrime(i))
		{
		    printf("%d\t", i);
	        j++;
	        if (j % 5 == 0)   //如此设计该语句中的表达式目的是为了保证每行只打印出5个素数！！！ 
	            printf("\n");
        }  
	} 
	
	return 0;
}

// 本函数的功能是：判断一个数i是不是素数，是的话，返回true；否则，返回false； 
bool IsPrime(int i)

{
	int j;
	
    for (j = 2; j < i; j++)
        if (i % j == 0)
		    break;
	
	if (i == j)
	    return true;
	else
	    return false;			 
}
/*
    1>    副函数的设计必须保证功能的单一性，这样可以提高代码的利用率 !
    2>    对于程序中要重复执行的一段代码，可以通过编写副函数来解决，同时，以后再碰到类似代码，直接调用就可以了！ 
*/ 
