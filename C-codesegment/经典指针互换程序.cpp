/*
                  2015.8.12  21:08
          在被调函数中通过定义两个指针变量为形参，来实现主函数中变量a与b值的互换！ 
*/
#include <stdio.h>

void huhuan(int *, int *);  //函数声明（函数原型）的形参可以省略不写 

int main()
{
	int a, b;
	
	a = 5;
	b = 10;
	printf("互换之前： a = %d, b = %d\n", a, b);
	
	huhuan(&a, &b); // 因为被调函数的形参被定义为指针变量，所以传递过去的是必须是a与b变量的地址才可以 
	printf("互换之后： a = %d, b = %d\n", a, b);
	
	return 0;
}

void huhuan(int *p, int *q)
{
	int t;
	
	t = *p;    //由于*p与*q数据类型均为int型，所以作为中间变量的t必须为int类型！！！注意！！！ 
	*p = *q;
	*q = t;     //等价于a与b两变量的直接互换，因为*P==a,*q==b.   
}
/*
   不难发现，通过在被调函数中定义指针变量p与q为形参，我们就可以改变主函数中变量的值，也就是所谓的“地址传递”
   虽然是在被调函数中，但指针变量p指向主函数中的a，指针变量q指向主函数中的b，所以*p与*q的互换就是直接在互换变量a
 与变量b内存单元所存储的值！   

*/
