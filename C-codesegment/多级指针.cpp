/*
                     2015.8.13  23:52
            验证多级指针的关系 
*/ 

#include <stdio.h>

int main()
{
	int i = 5;
	int *p = &i; // *p =i
	int **q = &p;  //二级指针变量保存的数据类型int *为变量的地址，q本身为int **数据类型   *q = p；**q = *p = i 
	int ***r = &q;// 三级指针变量保存的数据类型int**为变量的地址，r本身为int***数据类型  *r = q; ***r =**q=*p=i
	
	printf("结果为：%d  %d  %d  %d\n", i , *p, **q, ***r); //  验证多级指针变量之间的关系 
	
	return 0;
}
