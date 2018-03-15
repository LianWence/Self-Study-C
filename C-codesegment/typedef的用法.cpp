/*
         2015.8.19  10:22
    熟悉typedfe的用法  可以用其定义别名来简化结构体数据类型的书写   不是结构体变量本身         
*/ 
#include <stdio.h>

typedef struct student   //typedef 就是给数据类型struct student和struct student*取别名 别名可以代替原始数据类型 
{                       //同时减少同类数据类型代码量的书写 
	int age;
	char name[6];
	float score;
} ST, * PST;    //ST等价于struct student ， PST等价于struct student* 即PST为指针 

int main(void)
{    
	ST st;   //定义了一个结构体变量名为st普通变量 
	PST p = &st;  //定义了一个指向该结构体变量的指针p 其数据类型为struct student * 
	//  轮到typedef定义的别名上场了！！！！ 
    st.age = 19;      //根据上述typedef的定义，ST 就等价于struct student数据类型  或者是后者的别名 
    p->score = 92.5;
    printf("请输入该学生的名字:");
    scanf("%s", st.name); //此处不需要再加上&符号，因为该成员name本身就是地址 
	 
	printf("用typedef定义的另一种方式输出的结果为:\n");
	printf("age = %d\n", p->age);   //由上述定义可知，PST 等价于struct student *  所以PST指向于该结构体变量ST 
	printf("name = %s\n", p->name);
	printf("score = %.1f\n", st.score); 
	
	return 0;
}
