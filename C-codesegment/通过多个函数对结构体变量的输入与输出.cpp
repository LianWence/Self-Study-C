/*
                               2015.8.14  16:01
                   ͨ�������Խṹ������������������ͬʱҲ�����˺�������� 
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
    
	input(&ps);//�Խṹ�����������    �纯���޸���������ֵ�������ǵ�ַ���� 
	output(&ps); //�Խṹ����������    ֻ������Ļ���ʵ�ο��Ե�ַ���ݣ�Ҳ����ֵ���� 
	
	printf("�ýṹ�������ռ���ֽ���Ϊ��%d\n", sizeof(ps));  // ��ϸԭ��ò��ġ���������ԭ�� 
		
    return 0;	
}

void input(struct person *point)
{
	point->age = 30;    
	strcpy(point->name, "����");
	point->salary = 100000000000;  //�ڼ�����ڲ�ִ�еĻ���point->salary��ת����(*point).salary 
}

void output(struct person *pss)  //�˴����յ��ǵ�ַ���кܴ�����ԡ��������������ı���������ֵ�� 
{                                  //������ֵ����,����Ҳ�����˸ú����ĵ�һ���ܡ� 
	printf("���������ϢΪ������ = %d, ���� = %s, ��н = %lf����\n", pss->age, pss->name, pss->salary);
}
/*
        ������������Ǹú�����ĳһ������ֵ��������ñ��������������ܴ洢�Ŀռ�(�����˲���ϵͳΪ�ñ�������Ĵ洢�ռ�) 
        int���͵ı��������ױ������ֻҪֵд����ǧ�ڵĻ����ͻ������������������������������ 
        ��ַ���ݵ��ŵ�:ռ���ڴ��٣������ٶȿ� �������ж������ֵ 
        
*/
 
