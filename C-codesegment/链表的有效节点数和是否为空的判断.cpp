/*
               2015.8.19  21:46
          判断链表的有效节点数和是否为空 
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 

typedef struct node     //定义一个结构体数据类型   
{
	float score;   //定义节点的数据域 
	char name[10];    //定义节点的数据域 
	struct node *pNext;   //定义节点的指针域 
}NODE, *PNODE;  // NODE等价于struct node   PNODE等价于struct node * 

PNODE create_list(int);
void is_empty(PNODE);
void length_list(PNODE);
void traverse_list(PNODE);
void release_list(PNODE, int); 

int main(void)
{
	PNODE pHead = NULL;
	int len; 
	printf("请输入您想为给链表分配的有效节点的个数:len = ");
	scanf("%d", &len);
	
	pHead = create_list(len);  //动态构造一组链表，并返回头结点的地址 
	is_empty(pHead);     //判读该链表是否为空 
	length_list(pHead);
	traverse_list(pHead);   //对该链表进行遍历（专业术语） 
	release_list(pHead, len);  //对程序中构造的动态内存进行释放 
	
	return 0;
}

PNODE create_list(int len)
{
	int i;
	int val; //存储用户临时输入的数据
	PNODE pHead = NULL;
	
	pHead = (PNODE)malloc(sizeof(NODE));   //动态构造了一个头结点
	if (pHead == NULL)
	{
		printf("内存分配失败，程序即将终止\n");
		exit(-1);
	}
	
	PNODE pTail = pHead;  //将尾节点初始化成头结点 
	
	
	
	for (i = 0; i < len; i++)
	{
		
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));  //动态构造一个有效节点
		
		printf("请输入第%d个学生的名字(必须为中文名):", i + 1);
		scanf("%s", pNew->name);  //将用户输入的数据存储到该有效节点的数据中 
		printf("请输入该学生的成绩:score = ");
		scanf("%f", &pNew->score);//将用户输入的数据存储到该有效节点的数据中 
		
		pTail->pNext = pNew;   //将初始尾节点指向新节点，已指向成功！ 
		pNew->pNext = NULL;  //蒋新节点的指针域赋值为空 
		pTail = pNew;  //将初始尾节点转到新节点上。即pTail指向新节点 
	}
	 return pHead; 
}

void is_empty(PNODE pHead)
{
	if (pHead->pNext == NULL)
	{
		printf("该链表为空，程序即将终止!\n");
		exit(-1);
	}
	else
	{
		printf("该链表不为空！\n");
		return;
	}
}

void length_list(PNODE pHead)
{
	
	int cnt = 0;
	PNODE p = pHead->pNext;
	
	while (p != NULL)
	{
		p = p->pNext;
		cnt++;
	}
	printf("该链表的length = %d\n", cnt);
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;  //将指针变量p默认指向第一个有效节点 
	
	printf("遍历该链表的结果为:\n");
	while (p != NULL)
	{
		printf("%s 该学生的成绩为:%.2f\n", p->name, p->score);
		
		p = p->pNext;   //让指针变量p再次指向下一个有效节点 
	}
	return;
}

void release_list(PNODE pHead, int len)
{
	PNODE p = pHead->pNext;
	
	printf("释放后的结果为:\n");
	
	while(len >= 0)    //通过释放依次释放尾节点的的动态内存来解决内存泄露问题 
	{
		for ( int i = 0; i < len - 1; i++)	 //执行条件为:i < len - 1				
		    p = p->pNext;
		
		free(p);
		p = pHead->pNext;
		len--;
	}
	
	while (p != NULL)
	{
		printf("%s 该学生的成绩为:%.2f\n", p->name, p->score);
		
		p = p->pNext;
	}
}
