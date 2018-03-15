/*
                       2015.8.22   12:10
             队列的基本操作：出队，入队，遍历 
*/
#include <stdio.h>
#include <malloc.h>

typedef struct people
{
	char country[10];               //国家名 
	double amount;                  //人口总数 
} PEOPLE, *PPEOPLE; 

typedef struct queue     // 定义一个队列的数据类型 
{
	PPEOPLE pBase;          //指向那个结构体 
	int front;           //队列的头部 
	int rear;            //队列的尾部  
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
	QUEUE Q;         //先将该队列定义出来 
	
	len = initialize_queue(&Q);
	en_queue(&Q, len);
	out_queue(&Q, len);
	traverse_queue(&Q, len);
	release_queue(&Q, len);
	
	return 0;
} 

int initialize_queue(PQUEUE pQ)     //将该队列初始化 
{
	int len;
	
	printf("++++请输入要分配的个数:len = ");
	scanf("%d", &len);

    pQ->pBase = (PPEOPLE)malloc(sizeof(PEOPLE) * len);     //动态构造该复合数组 
    
    if (pQ->pBase == NULL)
    {
    	printf("动态内存分配失败,程序即将终止!\n");
    	exit(-1);
    }
    else
    {
    	pQ->front = 0;
        pQ->rear = 0;   //将队列中的参数初始化完成 
    }
    printf("^_^初始化成功^_^\n");
	return len;
}

void en_queue(PQUEUE pQ,int len)  //入队 
{
	char ch;
	
	do
	{
	    if (full_queue(pQ, len))
	    {
	    	printf("~_~该队列已满，无法进行存储~_~\n");
	    	return;
	    }
		else
		{
			printf("++++请输入国家名:");
			scanf("%s", pQ->pBase[pQ->rear].country);
			printf("++++请输入人口总数(单位:亿):");
			scanf("%lf", &pQ->pBase[pQ->rear].amount);	
			
			pQ->rear = (pQ->rear + 1) % len;  //每次入队，队尾参数也得随之改变 
			printf("^-^恭喜入队成功^_^\n");
			
			
		}
	    printf("****继续入队:Y/y  退出:其它任意键****:");		
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

void out_queue(PQUEUE pQ, int len)  //出队 
{
	char ch;
	
	do
	{
		if (empty_queue(pQ, len))
		{
			printf("~_~该队列为空，程序无法进行出队~_~\n");
			return; 	
		}
		else
		{
			printf("^_^国家:%s  总人口数:%.2f亿~_~出队成功\n", pQ->pBase[pQ->front].country, pQ->pBase[pQ->front].amount);
			pQ->front = (pQ->front + 1) % len;           //出队只能在队头 
		}
		printf("****继续出队:Y/y  退出:其它任意键****:");
		scanf(" %c", &ch);
	}while (ch == 'Y' || ch == 'y');
	
    return;	
}

bool empty_queue(PQUEUE pQ, int len)   //判断队列是否为空 
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
		printf("~__~该队列为空，程序无法进行遍历~__~\n");
		return; 
	}
	else
	{
		while(j != pQ->rear)
		{
			printf("####国家:%s   总人口数:%.2f亿####\n", pQ->pBase[j].country, pQ->pBase[j].amount);
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
		free(pQ->pBase + (len - 1));  //数组的地址:数组名+下标(即len -1 ) 
		len--;
	}

	while(j != pQ->rear)
	{
		printf("####国家:%s   总人口数:%.2f亿####\n", pQ->pBase[j].country, pQ->pBase[j].amount);
		j = (j + 1) % len;
	}
	
	return;
}
