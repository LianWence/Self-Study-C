/*
           2015.8.15  22:30
		   �����Ӧ��      
*/
#include <stdio.h>
#include <malloc.h>

struct Node * create_list(void);  // �������� 
void traverse_list(struct Node * );  //�������� 

struct Node 
{
	int data;     //������������� 
    struct Node *pNext;	  // ����ָ���� 
};

int main(void)
{
	struct Node *pHead = NULL;  //����һ�������͵�ͷָ�� 
	
	pHead = create_list();   //��ͷ���ĵ�ַ���ظ�ͷָ�� 
	traverse_list(pHead);    // ȷ��һ������ֻ��Ҫһ��ͷָ�뼴�ɣ�����ֻ��Ҫ��ͷָ���ֵ���ݹ�ȥ�Ϳ����� 
	
	return 0;
}

struct Node * create_list(void)
{
    int len;   //���������Ч�ڵ�ĸ��� 
    int i;
	int val;   //������ʱ����û�������յ��ֵ
	
	struct Node *pHead = (struct Node *)malloc(sizeof(struct Node));   //������һ���������Ч���ݵĶ�̬ͷ��� 
	  
	if (NULL == pHead)
	{
		printf("����ʧ�ܣ�������ֹ\n");
		exit(-1);   //��ֹ��������� 
	}
	
	struct Node *pTail = pHead;  
	pTail->pNext = NULL;  //��ָ������и�ֵ 
	
	printf("��������Ҫ����Ľڵ����:\n");
	scanf("%d", &len);
	
	for (i = 0; i < len; i++)
	{
	    printf("�������%d���ڵ��ֵ��", (i + 1));
		scanf("%d", &val);
		
		struct Node *pNew = (struct Node *)malloc(sizeof(struct Node)); //�����˴洢��Чֵ�Ķ�̬�ڵ� 
		if (NULL == pNew)
		{
			printf("����ʧ�ܣ���ֹ����\n");
			exit(-1);
		} 	
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead; 
}

void traverse_list(struct Node *pHead)
{
	struct Node *p = pHead->pNext;
	
	while (NULL != p)
	{
		printf("%d\n", p->data );
		p = p->pNext;
	}
	return;
}


