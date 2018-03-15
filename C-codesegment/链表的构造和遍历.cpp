/*
                   2015.8.19   17:09
               ͨ���ô���ģ����������ɣ���ֵ�������Լ��ͷ��������ڴ������    
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 

typedef struct node     //����һ���ṹ����������   
{
	float score;   //����ڵ�������� 
	char name[10];    //����ڵ�������� 
	struct node *pNext;   //����ڵ��ָ���� 
}NODE, *PNODE;  // NODE�ȼ���struct node   PNODE�ȼ���struct node * 

PNODE create_list(int);
void is_empty(PNODE);
void traverse_list(PNODE);
void release_list(PNODE, int); 

int main(void)
{
	PNODE pHead = NULL;
	int len; 
	printf("����������Ϊ������������Ч�ڵ�ĸ���:len = ");
	scanf("%d", &len);
	
	pHead = create_list(len);  //��̬����һ������������ͷ���ĵ�ַ 
	is_empty(pHead);    
	traverse_list(pHead);   //�Ը�������б�����רҵ��� 
	release_list(pHead, len);  //�Գ����й���Ķ�̬�ڴ�����ͷ� 
	
	return 0;
}

PNODE create_list(int len)
{
	int i;
	int val; //�洢�û���ʱ���������
	PNODE pHead = NULL;
	
	pHead = (PNODE)malloc(sizeof(NODE));   //��̬������һ��ͷ���
	if (pHead == NULL)
	{
		printf("�ڴ����ʧ�ܣ����򼴽���ֹ\n");
		exit(-1);
	}
	
	PNODE pTail = pHead;  //��β�ڵ��ʼ����ͷ��� 
	pTail->pNext = NULL;
	
	for (i = 0; i < len; i++)
	{
		
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));  //��̬����һ����Ч�ڵ�
		
		printf("�������%d��ѧ��������(����Ϊ������):", i + 1);
		scanf("%s", pNew->name);  //���û���������ݴ洢������Ч�ڵ�������� 
		printf("�������ѧ���ĳɼ�:score = ");
		scanf("%f", &pNew->score);//���û���������ݴ洢������Ч�ڵ�������� 
		
		pTail->pNext = pNew;   //����ʼβ�ڵ�ָ���½ڵ㣬��ָ��ɹ��� 
		pNew->pNext = NULL;  //���½ڵ��ָ����ֵΪ�� 
		pTail = pNew;  //����ʼβ�ڵ�ת���½ڵ��ϡ���pTailָ���½ڵ� 
	}
	 return pHead; 
}

void is_empty(PNODE pHead)
{
	if (pHead->pNext == NULL)
	{
		printf("������Ϊ�գ����򼴽���ֹ!\n");
		exit(-1);
	}
	else
	{
		printf("������Ϊ�գ�\n");
		return;
	}
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;  //��ָ�����pĬ��ָ���һ����Ч�ڵ� 
	
	printf("����������Ľ��Ϊ:\n");
	while (p != NULL)
	{
		printf("%s ��ѧ���ĳɼ�Ϊ:%.2f\n", p->name, p->score);
		
		p = p->pNext;   //��ָ�����p�ٴ�ָ����һ����Ч�ڵ� 
	}
	return;
}

void release_list(PNODE pHead, int len)
{
	PNODE p = pHead->pNext;
	
	printf("�ͷź�Ľ��Ϊ:\n");
	
	while(len >= 0)    //ͨ���ͷ������ͷ�β�ڵ�ĵĶ�̬�ڴ�������ڴ�й¶���� 
	{
		for ( int i = 0; i < len - 1; i++)	 //ִ������Ϊ:i < len - 1				
		    p = p->pNext;
		
		free(p);
		p = pHead->pNext;
		len--;
	}
	
	while (p != NULL)
	{
		printf("%s ��ѧ���ĳɼ�Ϊ:%.2f\n", p->name, p->score);
		
		p = p->pNext;
	}
}
/*
    ͨ���Լ�����˫��ѭ���������ͷŸ�����Ķ�̬�ڴ棬�����ڴ�й¶���鷳 
*/
