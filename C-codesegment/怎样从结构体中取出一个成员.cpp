/*
           2015.8.14  12:06
        ��δӽṹ�������ȡ��һ����Ա����Ϣ 
*/
#include <stdio.h>

struct student
{
	int age;
	float score;
	double height;
};   

int main()
{
	struct student doubi;  //����һ���ṹ�����doubi,��Ա���ֱ�Ϊ������������ 
	struct student *point = &doubi;  //ָ�����point��������������Ϊstruct student����doubi�ĵ�ַ����*point=doubi 
	
	point->height = 178.56;  //�ڼ�����ڲ��ᱻת���ɣ�*point��.height,�ȼ���doubi.height  
	point->score = 89.5;  //ԭ��ͬ�� 
	doubi.age = 21;
	
	printf("��ѧ������ϢΪ:height = %lf, score = %f, age = %d", point->height, doubi.score, point->age); 
	
	
	return 0;
}
