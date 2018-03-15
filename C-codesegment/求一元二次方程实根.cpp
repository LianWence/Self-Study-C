/*
       2015.8.10 10:06 
       求一元二次方程的实根 
*/ 

#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, c;
	double x1, x2;
	double delta;
	char ch;
    do	
	{
	    printf ("请按要求依次输入该一元二次方程的各个系数：\n");
	
	    printf ("请输入:a = ");
	    scanf ("%lf", &a);
	
	    printf ("请输入:b = ");
	    scanf ("%lf", &b);
	
	    printf ("请输入:c = ");
	    scanf ("%lf", &c);
	
	    delta = b*b - 4*a*c;
	
	
	
		if (delta > 0)
		{   
		    x1 = (-b + sqrt(delta)) / (2*a);
		    x2 = (-b - sqrt(delta)) / (2*a);
		    printf ("有两个解:x1 = %lf, x2 = %lf\n", x1, x2);
		}
		else if (0 == delta)
		{
			 x1 = x2 = (-b) / (2*a);
			printf("有一个解:x1 = x2 = %lf\n", x1, x2);
		}   
		else
		     printf ("该方程无实数解\n");	    
		
		printf ("如果要继续，请按y键，否则按其他任意键退出:");
		scanf (" %c", &ch);  //进行人机交互的最关键一步，标准库函数scanf的控制符%c前面必须有得有空格！！！千万注意！ 
		
	} while ('y'==ch || 'Y'==ch);
	
	printf ("谢谢您的使用，再见！\n");
	return 0;
}
/*
   do-while循环的成功应用----实现人机交互
   还有scanf标准库函数是实现人机交互的关键一步，控制符%c前面要加上空格！详细参考  老外出版的《C Primer Plus》
   这本书里面详细讨论了空白符的问题。 

*/ 


