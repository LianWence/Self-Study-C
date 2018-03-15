
/*
                      2015.8.11   10:16             
            通过用户自定义函数作为被调函数，来判断一个数是不是整数 
*/ 

#include <stdio.h>

bool IsPrime(int val)  //bool 为C语言中的新数据类型，且只包括数据true和数据false，分别对应的真值为1和0！ 

{
	int i;
	
	for (i = 2; i < val ; i++)
	{
		if (val % i == 0)     //根据素数的定义，等价于任意一个整数如果不能被2和该整数减一的数之间的任意数整除（余数不为0），那么该数为素数！ 
	        break;
	}
    if (i == val)
        return true;    //return语句执行完毕后，会终止该被调函数！ 数据true对应的真值为1！ 
    else
	    return false;   //数据false对应的真值为0，有bool数据类型规定的    
} 

int main(void)

{
	int prime;
  	
  	printf("请任意输入一个您想判断的整数:");
  	scanf("%d", &prime);
  	
	if (IsPrime(prime))  //表达式非零即为真，零为假！ 同时，return语句将值返回到被调用函数处，也就是此处！ 
	    printf("该数为素数\n");
	else 
        printf("该数不是素数\n");	
	
	return 0;
}
