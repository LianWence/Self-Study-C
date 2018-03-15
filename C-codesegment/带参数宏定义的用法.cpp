/*
           2015.8.30       8:22
         测试带参宏定义的用法 
*/
#include <stdio.h>

#define S1(a, b) a * b          //注意带参宏定义的括号的使用 ，避免造成运算逻辑错误 
#define S2(a, b) ((a) * (b))                      
#define max(a, b)  ((a) > (b) ? (a) : (b))

int main(void)
{
	int x = 3, y = 4, i = 5, j = 6, a = 5, b = 6, s, z;
	
	s = S1(x + y, x - y);  //等价于s = x + y * x - y  所以值为:11 
	printf("第一种情况:%d\n", s);
	
	s = S2(x + y, x - y);   //等价于s = ((x + y) * (x -y))   
	printf("第二种情况:%d\n", s);
	
	z = max(i++, j++);        //即:z = ((i++) > (j++) ? (i++) : (j++)) 这种自增形式，是先使用变量然后自增 
	printf("第三种情况:%d\n", z);  // z = 7, i = 6, j = 8 
	
	z = max(++a, ++b);          //同上述一样， 
	printf("第三种情况:%d\n", z);// z = 8,j = 8, i = 6
}
/*
      进行宏定义替换时，只对参数进行形式上的替换，不做任何的运算。 
*/
