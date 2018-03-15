/*
              2015.8.14  23:32
              �򵥵�ѧ������ϵͳ 
*/
#include <stdio.h>
#include <malloc.h>

void input(struct student *, int );
void order(struct student *, int );
void output(struct student *, int );

struct student 
{
	float math;
	char name[6];
	int grade;
}; 

int main(void)
{
	int len;
	struct student *pArr;
	
	printf("������ѧ���ĸ�����");
	scanf("%d", &len);
	pArr = (struct student *)malloc(sizeof(struct student) * len); //���춯̬һά�ṹ������ 
	
	input(pArr, len); //pArr = &pArr[0]  ��һά��̬������׸�Ԫ�صĵ�ַ�ͳ��ȴ��ݹ�ȥ  
	order(pArr, len);
	output(pArr, len);//����βζ�Ϊһ��ָ��Ϳ����ˣ��β�Ҳ�ö����� 
	
	printf("��̬�ڴ��ͷ�֮ǰ�������\n");
	printf("����:%s   �༶:%d   �ɼ�:%6.2f\n", pArr[0].name, pArr[0].grade, pArr[0].math);
	free(pArr);
	printf("��̬�ڴ��ͷź�������\n");
	printf("����:%s   �༶:%d   �ɼ�:%4.2f\n", pArr[0].name, pArr[0].grade, pArr[0].math); 
	
	return 0;
}

void input(struct student *q, int len)
{
	int i;
	
	printf("�����������ѧ������Ϣ��\n");
	for (i = 0; i < len; i++)
	{
		printf("��%d��ѧ������ϢΪ��\n", (i + 1));
		printf("��ѧ�ɼ�: ");
		scanf("%f", &q[i].math);   //��Ϊq=pArr һ��ָ���Ǹ���̬һά����ĵ�һ��Ԫ�ص����ֽڵ�ַ 
		printf("����Ϊ��");
		scanf("%s", q[i].name);  //�ýṹ���Ա�е�nameΪ�ַ�������������ַ������ʵ�β���Ҫ�ټ���ȡ��ַ��& 
		printf("�༶Ϊ��");
		scanf("%d", &q[i].grade);
	} 
} 

void order(struct student *q, int len)
{
	int i, j;
	struct student t;
	
	for (i = 0; i < len - 1 ; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (q[i].math < q[j].math)   //<���������� ��>���������� 
			{
				t = q[i];
				q[i] = q[j];
				q[j] = t;   //ֻ�ǽ���һ��λ�ã����ǽ���һ�¸ýṹ���еĳ�Աֵ����ô�������Ϣ���Ҳ������Բ��Ϻ��� 
			}
			
		}
	}
} 

void output(struct student *q, int len)
{
	int i;
	
	printf("���ɼ������Ľ��Ϊ��\n");
	for (i = 0;i < len; i++)
	{
		printf("����:%s   �༶:%d   �ɼ�:%4.2f\n", q[i].name, q[i].grade, q[i].math); //q=pArr ��qҲָ��ýṹ��һά��̬���� 
	}
}
