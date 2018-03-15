/*
              2015.8.22   18:10
        用递归求阶乘 
*/
#include <stdio.h>

int f(int );

int main(void)
{
	int val;
	
	printf("****请任意输入一个整数:");
	scanf("%d", &val);
	
	printf("該阶乘为：%d!=%d\n", val, f(val));
	
	return 0;
}

int f(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return f(n - 1) * n;  //一级一级调用自己直到f（1） 
	}
}
/*
       自己调用自己的原理同调用其他函数的原理相同!
	   f(n)               f(n-1)            直到:   f(1) 
	   {                {                      {  
           .....     	  .....                   .....    
         f(n-1)*n	      f(n-2)*(n-1)            return 1;   一级一级将值返回   
       }                }                       }

*/

