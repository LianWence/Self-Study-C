/*
                               2015.8.14  16:01
                   通过函数对结构体变量的输入与输出，同时也发现了函数的溢出 
*/
#include <stdio.h>
#include <string.h>

void input(struct person *);
void output(struct person * ); 

struct person 
{
	int age;
	char name[6];
	double salary;       
};

int main()
{
    struct person ps;
    
	input(&ps);//对结构体变量的输入    跨函数修改主函数的值，必须是地址传递 
	output(&ps); //对结构体变量的输出    只是输出的话，实参可以地址传递，也可以值传递 
	
	printf("该结构体变量所占的字节数为：%d\n", sizeof(ps));  // 详细原理得查阅《计算机组成原理》 
		
    return 0;	
}

void input(struct person *point)
{
	point->age = 30;    
	strcpy(point->name, "马云");
	point->salary = 100000000000;  //在计算机内部执行的话，point->salary会转化成(*point).salary 
}

void output(struct person *pss)  //此处接收的是地址，有很大风险性。如果处理不当，会改变主函数的值。 
{                                  //建议是值传递,这样也体现了该函数的单一功能。 
	printf("该人物的信息为：年龄 = %d, 名字 = %s, 年薪 = %lf美金\n", pss->age, pss->name, pss->salary);
}
/*
        函数溢出，就是该函数中某一变量的值超出了其该变量数据类型所能存储的空间(超出了操作系统为该变量分配的存储空间) 
        int类型的变量很容易被溢出，只要值写到几千亿的话，就会轻松溢出，哈哈哈哈哈哈哈哈哈！ 
        地址传递的优点:占用内存少，传输速度快 ，可以有多个返回值 
        
*/
 
