/*
           2015.8.22    22:07
       用递归的思想求和    
*/ 
#include <stdio.h>

long sum(int);

int main(void)
{
	printf("1+2+3+....+100=%d", sum(100));
	
	return 0;
}

long sum(int n)
{
	if (n == 1)
		return 1;
	else 
		return sum(n - 1) + n;
}
