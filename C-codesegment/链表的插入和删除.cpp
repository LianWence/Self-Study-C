/*
               2015.8.20         18:30
            ����Ĳ����ɾ���Ĳ���   
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 
#include <string.h>

typedef struct node     //����һ���ṹ����������   
{
	float score;   //����ڵ�������� 
	char name[10];    //����ڵ�������� 
	struct node *pNext;   //����ڵ��ָ���� 
}NODE, *PNODE;  // NODE�ȼ���struct node   PNODE�ȼ���struct node * 

PNODE create_list(int);
void insert_list(PNODE);
void delete_list(PNODE); 
void is_empty(PNODE);
int length_list(PNODE);
void sort_list(PNODE, int);
void traverse_list(PNODE);
void release_list(PNODE, int); 

int main(void)
{
	PNODE pHead = NULL;
	int len; 
	printf("����������Ϊ������������Ч�ڵ�ĸ���:len = ");
	scanf("%d", &len);
	
	pHead = create_list(len);  //��̬����һ������������ͷ���ĵ�ַ 
	insert_list(pHead);   //�������в���һ���ڵ�
	delete_list(pHead);   //ɾ�������е�һ���ڵ� 
	is_empty(pHead);     //�ж��������Ƿ�Ϊ�� 
	len = length_list(pHead);
	sort_list(pHead, len); //������������� 
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

void insert_list(PNODE pHead)
{
	int i = 0;
	int pos;
	PNODE p = pHead;
	
	printf("���������ڵ��λ�ã�pos = ");
	scanf("%d", &pos);
	
	while (p != NULL && i < pos - 1)   //ѭ����Ŀ������pָ���pos���ڵ��ǰһ���ڵ��������������һ���ڵ� 
	{                                 //i < pos��pos<�ڵ����Ļ���ѭ��ʹ��pָ���pos���ڵ��λ�� 
		p = p->pNext;
		i++;               // i�Ƕ��٣�p��ָ��ڼ����ڵ� 
	}
	                       // p�����Զ�λ��������һ���ڵ㴦 
	if (p == NULL || i > pos - 1) //��p=NULLʱ����ζ��posλ��ԶԶ������Ч�ڵ���  ����Ԥ��pos<=0����� 
	{
		printf("posλ�������޷�ִ�в������!\n");
		return;
	}
	                                       //���ˣ�p��ָ���pos���ڵ��ǰһ���ڵ� 
	PNODE pNew = (PNODE)malloc(sizeof(NODE)); //��̬�����½ڵ㣬���������ֽڵ�ַ 
	

	printf("�������ѧ������(Ҫ����������):");
	scanf("%s", pNew->name);
	printf("������: score = ");
	scanf("%f", &pNew->score);
	
	PNODE q = p->pNext;   //�����м��������p������Ǹ��ڵ��ַ 
	p->pNext = pNew;     // pָ���½ڵ� 
	pNew->pNext = q;       // �½ڵ�ָ���һ���ڵ� 
	
	printf("inserteing succeeded!\n");
	return; 
}

void delete_list(PNODE pHead)
{
	int i = 0;
	int pos;
	PNODE p = pHead;
	
	printf("��������Ҫɾ���ڵ��λ��:pos = ");
	scanf("%d", &pos);
	
	while (p->pNext != NULL && i < pos - 1)  //��ѭ���ṹʹ��p����ָ���pos���ڵ��ǰһ���ڵ� ǰ����pos <= len 
	{                                     //pָ��Ľڵ��ָ����Ϊ��ʱ��˵��posλ���������޷��ҵ����������һ���ڵ� 
		p = p->pNext;             // ��pos = len + 1ʱ���˳�ѭ�� 
		i++;                  
	}
	                     //p���ֻ�ܶ�λ�������ڶ����ڵ㴦 
	if (i > pos - 1 || p->pNext == NULL)  //��ֹ�û���������  ���ߵ�pos = len +1 ʱ��Ҳ�ᱻ��ֹ 
	{
		printf("pos�������󣬳����޷�ִ��!\n");
		return;
	} 
	
	PNODE q = p->pNext;
	printf("ɾ��ѧ��%s �ɹ�,��ɼ�Ϊ:%.2f!\n", p->pNext->name, p->pNext->score); 
	p->pNext = p->pNext->pNext; 
	free(q);
	q = NULL; 
	
	return;
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

int length_list(PNODE pHead)
{
	
	int cnt = 0;
	PNODE p = pHead->pNext;
	
	while (p != NULL)
	{
		p = p->pNext;
		cnt++;
	}
	printf("�������length = %d\n", cnt);
	return cnt;
}

void sort_list(PNODE pHead, int len)  //ͨ�����ڵ������������г�Ա���������ﵽ�ı�ڵ��Ⱥ�˳��������㷨 
{
    int i, j;
	char h[10];
	float t;
    
    PNODE p = pHead->pNext;
	PNODE q = p->pNext;
	
	for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext)  //˫������ѭ���ṹ 
	{                                                  //˫������ѭ��  �м��ڲ�ѭ�����ĳ�ʼ������������© 
		for (j = i + 1, q = p->pNext; j < len ; j++ , q = q->pNext)    //j�ĳ�ʼ������Ϊ: j = i + 1   q=p->pNext����������ȱ�� 
		{
			if (p->score < q->score)
			{
			    t = p->score;
				p->score = q->score;
				q->score = t;
			
				strcpy(h, p->name);   //�ַ�������໥��ֵ��ֻ��ͨ��strcpy������ʵ�֣�����ֱ�Ӹ�ֵ������ 
				strcpy(p->name, q->name);  //�м�����ַ�����h���������ַ����飬ע��H�Ĵ����ʽ 
				strcpy(q->name, h);
	           		
			}
		}
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
		
		free(p);             //ͷ���Ҳ�ᱻ�ͷţ���len=0ʱ�� 
		p = pHead->pNext;
		len--;
	}
	
	free(pHead);
	
	while (p != NULL)
	{
		printf("%s ��ѧ���ĳɼ�Ϊ:%.2f\n", p->name, p->score);
		
		p = p->pNext;
	}
}
