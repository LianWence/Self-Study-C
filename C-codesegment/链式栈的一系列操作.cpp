/*
               2015.8.21   12:24
          ����ʽջִ�г�ʼ����ѹջ����ջ��������һϵ�еĲ��� 
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
	float score;           //������ 
	char name[10];          //������ 
	struct node *pNext;  //ָ���� 
}NODE, *PNODE;

typedef struct stack
{
	PNODE pTop;   //ջ��ָ�� 
	PNODE pBottom;   //ջ��ָ�� 
}STACK, *PSTACK;

void initialize_stack(PSTACK);
void push_stack(PSTACK);
void pop_stack(PSTACK);
bool is_empty(PSTACK);
void traverse_stack(PSTACK);
void release_stack(PSTACK);

int main(void)
{
	STACK sk;
	
	initialize_stack(&sk);
    push_stack(&sk);
    pop_stack(&sk);
    traverse_stack(&sk);
	release_stack(&sk);
	
	return 0;
}

void initialize_stack(PSTACK pS)    //��ʼ����ʽջ������pTop��pBottom��� 
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));    //��̬����һ�������ϵġ�ͷ��㡱 
	
	if(pS->pTop == NULL)
	{
		printf("�ڴ��ʧ�ܣ����򼴽���ֹ!\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;               //��ָ���ָ��ͬһ���ڵ��λ�� 
	    pS->pBottom->pNext = NULL;            //��ָ��ָ���ͬһ���ڵ��ָ����Ϊ�գ������������е�ͷ��� 
	}
	return; 
}

void push_stack(PSTACK pS)   // ����ѹջ 
{
	char ch;
	
	do
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));  //��̬������Ч�ڵ㣬�������ֽڵ�ַ���ظ�ָ��pNew
		
		pNew->pNext = pS->pTop; //Ĭ���¹���Ľڵ�ָ����һ���ڵ㼴ָ���򱣴�����ڵ�ĵ�ַ
		pS->pTop = pNew; //pTop��Զָ��ջ���ڵ㣬����pTopҪ�����½ڵ�ĵ�ַ 
		            //���¹���ڵ����������и�ֵ 
		printf("----������ѧ������:name = ");
		scanf("%s", pNew->name);    // ��Ϊ��Ա���ַ�������������ǵ�ַ�����Բ���Ҫ��ȡ��ַ����& 
		printf("----�������ѧ���ɼ�:score = ");
		scanf("%f", &pNew->score);
		 
	    printf("( ****����:Y/y  �˳�:���������****):");
		scanf(" %c", &ch);	 
	} while (ch == 'Y' || ch == 'y');
	
	return;
}  

void traverse_stack(PSTACK pS)        //��������ʽջ����������������� 
{
	PNODE r = pS->pTop;
	
	printf("#####������Ľ��Ϊ:\n");
	while (r != pS->pBottom)     //����ջ�׽ڵ㲻����⣬������Ч�ڵ�ȫ����� 
	{
		printf("ѧ��:%-5s ------ �ɼ�:%3.2f \n ", r->name, r->score);
		r = r->pNext;   //r�ٴ�ָ����һ���ڵ� 
	}
	return;
}

void pop_stack(PSTACK pS)    //   ����Ч�ڵ���г�ջ 
{
	char ch;
	
	if (is_empty(pS))
	{
		printf("++++����ʽջΪ�գ������޷�ִ�г�ջ++++\n");
		return; 
	}
	else
	{
		PNODE r = pS->pTop;
		printf("^-^��������ִ�г�ջ^-^\n");
		
		do
		{
			printf("****ѧ��:%-5s �ɼ�:%3.2f####��ջ�ɹ�****\n", r->name, r->score);
			pS->pTop = r->pNext;     //pTop ָ����һ��ջ���ڵ� 
			free(r);   // ��rָ��Ľڵ��ջ 
		    r = pS->pTop;  //r�ٴ�ָ��ջ���ڵ� 
		    
		    printf("^+^������ջ:Y/y �˳�:���������^+^:");
		    scanf(" %c", &ch);
		}while (r != pS->pBottom && (ch == 'Y' || ch == 'y'));   //����ѭ����ǰ����r���ܵ���pBottom�����û�������Y��y 
	}
	
	return;
}

bool is_empty(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)
	    return true;
	else
	    return false;    
}

void release_stack(PSTACK pS)   //�ͷŶ�̬�ڴ� 
{
	PNODE q;
	PNODE r = pS->pTop;  
	
	while (r != NULL)
	{
		q = r->pNext;   //ָ�����q��Զָ��rָ��ڵ��������һ���ڵ�
		free(r);
		r = q;    //ָ�����r�ٴ�ָ����һ���ڵ� 
	}
	 
	traverse_stack(pS);  //��鶯̬�ڴ��Ƿ��ͷųɹ� 
	
	return;
}
