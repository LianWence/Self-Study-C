/*
         2015.8.19  10:22
    ��Ϥtypedfe���÷�  �������䶨��������򻯽ṹ���������͵���д   ���ǽṹ���������         
*/ 
#include <stdio.h>

typedef struct student   //typedef ���Ǹ���������struct student��struct student*ȡ���� �������Դ���ԭʼ�������� 
{                       //ͬʱ����ͬ���������ʹ���������д 
	int age;
	char name[6];
	float score;
} ST, * PST;    //ST�ȼ���struct student �� PST�ȼ���struct student* ��PSTΪָ�� 

int main(void)
{    
	ST st;   //������һ���ṹ�������Ϊst��ͨ���� 
	PST p = &st;  //������һ��ָ��ýṹ�������ָ��p ����������Ϊstruct student * 
	//  �ֵ�typedef����ı����ϳ��ˣ������� 
    st.age = 19;      //��������typedef�Ķ��壬ST �͵ȼ���struct student��������  �����Ǻ��ߵı��� 
    p->score = 92.5;
    printf("�������ѧ��������:");
    scanf("%s", st.name); //�˴�����Ҫ�ټ���&���ţ���Ϊ�ó�Աname������ǵ�ַ 
	 
	printf("��typedef�������һ�ַ�ʽ����Ľ��Ϊ:\n");
	printf("age = %d\n", p->age);   //�����������֪��PST �ȼ���struct student *  ����PSTָ���ڸýṹ�����ST 
	printf("name = %s\n", p->name);
	printf("score = %.1f\n", st.score); 
	
	return 0;
}
