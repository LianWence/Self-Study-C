/*
                           2015.8.11  13:45
           通过设计两个副函数来解决----从1到某个数之间所有为素数的输出！！！ 
*/

#include <stdio.h> 

void output(int val);  //函数声明，或者是函数原型 
bool IsPrime(int i);   //函数声明，或者是函数原型 

int main()
{
	int val;
	int i, j;
	
	j = 0;
	
	printf("请输入您想判断的最大数的边界值：");
	scanf("%d", &val);
	
	printf("2到%d之间是素数的为：\n", val);
	
	output(val);
	
	
	
	return 0;
}

  //  本函数功能是：对从1到某个数之间所有为素数的数的有序打印！！！ 
void output(int val)
{
	int i;
	int j = 0; 
	
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
	
}

//  本函数功能是： 判断i是不是素数，是的话，返回true；否则返回false！ 
bool IsPrime(int i) 
{
	int j;
	
    for (j = 2; j < i; j++)
    {
        if (i % j == 0)
		    break;
    } 
	if (i == j)
	    return true;
	else
	    return false;			 
}
