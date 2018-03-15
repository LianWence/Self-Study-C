/*
                       2015.8.22   12:10
             ���еĻ������������ӣ���ӣ����� 
*/
#include <stdio.h>
#include <malloc.h>

typedef struct people
{
	char country[10];               //������ 
	double amount;                  //�˿����� 
} PEOPLE, *PPEOPLE; 

typedef struct queue     // ����һ�����е��������� 
{
	PPEOPLE pBase;          //ָ���Ǹ��ṹ�� 
	int front;           //���е�ͷ�� 
	int rear;            //���е�β��  
}QUEUE, *PQUEUE;

int initialize_queue(PQUEUE);
void en_queue(PQUEUE, int);
bool full_queue(PQUEUE,int);
void out_queue(PQUEUE, int);
bool empty_queue(PQUEUE, int);
void traverse_queue(PQUEUE, int);
void release_queue(PQUEUE, int);

int main(void)
{
	int len;
	QUEUE Q;         //�Ƚ��ö��ж������ 
	
	len = initialize_queue(&Q);
	en_queue(&Q, len);
	out_queue(&Q, len);
	traverse_queue(&Q, len);
	release_queue(&Q, len);
	
	return 0;
} 

int initialize_queue(PQUEUE pQ)     //���ö��г�ʼ�� 
{
	int len;
	
	printf("++++������Ҫ����ĸ���:len = ");
	scanf("%d", &len);

    pQ->pBase = (PPEOPLE)malloc(sizeof(PEOPLE) * len);     //��̬����ø������� 
    
    if (pQ->pBase == NULL)
    {
    	printf("��̬�ڴ����ʧ��,���򼴽���ֹ!\n");
    	exit(-1);
    }
    else
    {
    	pQ->front = 0;
        pQ->rear = 0;   //�������еĲ�����ʼ����� 
    }
    printf("^_^��ʼ���ɹ�^_^\n");
	return len;
}

void en_queue(PQUEUE pQ,int len)  //��� 
{
	char ch;
	
	do
	{
	    if (full_queue(pQ, len))
	    {
	    	printf("~_~�ö����������޷����д洢~_~\n");
	    	return;
	    }
		else
		{
			printf("++++�����������:");
			scanf("%s", pQ->pBase[pQ->rear].country);
			printf("++++�������˿�����(��λ:��):");
			scanf("%lf", &pQ->pBase[pQ->rear].amount);	
			
			pQ->rear = (pQ->rear + 1) % len;  //ÿ����ӣ���β����Ҳ����֮�ı� 
			printf("^-^��ϲ��ӳɹ�^_^\n");
			
			
		}
	    printf("****�������:Y/y  �˳�:���������****:");		
		scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
	return;	
}

bool full_queue(PQUEUE pQ, int len)
{
	if (pQ->front == (pQ->rear + 1) % len)
		return true;
	else
		return false;
} 

void out_queue(PQUEUE pQ, int len)  //���� 
{
	char ch;
	
	do
	{
		if (empty_queue(pQ, len))
		{
			printf("~_~�ö���Ϊ�գ������޷����г���~_~\n");
			return; 	
		}
		else
		{
			printf("^_^����:%s  ���˿���:%.2f��~_~���ӳɹ�\n", pQ->pBase[pQ->front].country, pQ->pBase[pQ->front].amount);
			pQ->front = (pQ->front + 1) % len;           //����ֻ���ڶ�ͷ 
		}
		printf("****��������:Y/y  �˳�:���������****:");
		scanf(" %c", &ch);
	}while (ch == 'Y' || ch == 'y');
	
    return;	
}

bool empty_queue(PQUEUE pQ, int len)   //�ж϶����Ƿ�Ϊ�� 
{
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}

void traverse_queue(PQUEUE pQ, int len)
{
	int j = pQ->front; 
	
	if (empty_queue(pQ, len))
	{
		printf("~__~�ö���Ϊ�գ������޷����б���~__~\n");
		return; 
	}
	else
	{
		while(j != pQ->rear)
		{
			printf("####����:%s   ���˿���:%.2f��####\n", pQ->pBase[j].country, pQ->pBase[j].amount);
			j = (j + 1) % len;
		}
	}
	return;
}

void release_queue(PQUEUE pQ, int len)
{
	int j = pQ->front; 
	

	while (len > 0)
	{	
		free(pQ->pBase + (len - 1));  //����ĵ�ַ:������+�±�(��len -1 ) 
		len--;
	}

	while(j != pQ->rear)
	{
		printf("####����:%s   ���˿���:%.2f��####\n", pQ->pBase[j].country, pQ->pBase[j].amount);
		j = (j + 1) % len;
	}
	
	return;
}
