/*
           2015.8.15  22:30
		   链表的应用      
*/
#include <stdio.h>
#include <malloc.h>

struct Node * create_list(void);  // 函数声明 
void traverse_list(struct Node * );  //函数声明 

struct Node 
{
	int data;     //定义基本数据域 
    struct Node *pNext;	  // 定义指针域 
};

int main(void)
{
	struct Node *pHead = NULL;  //定义一个空类型的头指针 
	
	pHead = create_list();   //将头结点的地址返回给头指针 
	traverse_list(pHead);    // 确定一个链表只需要一个头指针即可，所以只需要将头指针的值传递过去就可以了 
	
	return 0;
}

struct Node * create_list(void)
{
    int len;   //用来存放有效节点的个数 
    int i;
	int val;   //用来临时存放用户输入的终点的值
	
	struct Node *pHead = (struct Node *)malloc(sizeof(struct Node));   //分配了一个不存放有效数据的动态头结点 
	  
	if (NULL == pHead)
	{
		printf("分配失败，程序终止\n");
		exit(-1);   //终止程序的运行 
	}
	
	struct Node *pTail = pHead;  
	pTail->pNext = NULL;  //对指针域进行赋值 
	
	printf("请输入您要输入的节点个数:\n");
	scanf("%d", &len);
	
	for (i = 0; i < len; i++)
	{
	    printf("请输入第%d个节点的值：", (i + 1));
		scanf("%d", &val);
		
		struct Node *pNew = (struct Node *)malloc(sizeof(struct Node)); //分配了存储有效值的动态节点 
		if (NULL == pNew)
		{
			printf("分配失败，终止程序\n");
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


