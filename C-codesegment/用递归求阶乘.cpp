/*
              2015.8.22   18:10
        �õݹ���׳� 
*/
#include <stdio.h>

int f(int );

int main(void)
{
	int val;
	
	printf("****����������һ������:");
	scanf("%d", &val);
	
	printf("ԓ�׳�Ϊ��%d!=%d\n", val, f(val));
	
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
		return f(n - 1) * n;  //һ��һ�������Լ�ֱ��f��1�� 
	}
}
/*
       �Լ������Լ���ԭ��ͬ��������������ԭ����ͬ!
	   f(n)               f(n-1)            ֱ��:   f(1) 
	   {                {                      {  
           .....     	  .....                   .....    
         f(n-1)*n	      f(n-2)*(n-1)            return 1;   һ��һ����ֵ����   
       }                }                       }

*/

