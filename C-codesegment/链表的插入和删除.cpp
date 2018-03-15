/*
               2015.8.20         18:30
            链表的插入和删除的操作   
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 
#include <string.h>

typedef struct node     //定义一个结构体数据类型   
{
	float score;   //定义节点的数据域 
	char name[10];    //定义节点的数据域 
	struct node *pNext;   //定义节点的指针域 
}NODE, *PNODE;  // NODE等价于struct node   PNODE等价于struct node * 

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
	printf("请输入您想为给链表分配的有效节点的个数:len = ");
	scanf("%d", &len);
	
	pHead = create_list(len);  //动态构造一组链表，并返回头结点的地址 
	insert_list(pHead);   //往链表中插入一个节点
	delete_list(pHead);   //删除链表中的一个节点 
	is_empty(pHead);     //判读该链表是否为空 
	len = length_list(pHead);
	sort_list(pHead, len); //对链表进行排序 
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
	pTail->pNext = NULL; 
	
	
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

void insert_list(PNODE pHead)
{
	int i = 0;
	int pos;
	PNODE p = pHead;
	
	printf("请输入插入节点的位置：pos = ");
	scanf("%d", &pos);
	
	while (p != NULL && i < pos - 1)   //循环的目的是让p指向第pos个节点的前一个节点或者是链表的最后一个节点 
	{                                 //i < pos且pos<节点数的话，循环使得p指向第pos个节点的位置 
		p = p->pNext;
		i++;               // i是多少，p就指向第几个节点 
	}
	                       // p最多可以定位到倒数第一个节点处 
	if (p == NULL || i > pos - 1) //当p=NULL时，意味着pos位置远远超出有效节点数  后者预防pos<=0的情况 
	{
		printf("pos位置有误，无法执行插入操作!\n");
		return;
	}
	                                       //至此，p已指向第pos个节点的前一个节点 
	PNODE pNew = (PNODE)malloc(sizeof(NODE)); //动态构造新节点，并返回首字节地址 
	

	printf("请输入该学生姓名(要求是中文名):");
	scanf("%s", pNew->name);
	printf("请输入: score = ");
	scanf("%f", &pNew->score);
	
	PNODE q = p->pNext;   //构造中间变量保存p后面的那个节点地址 
	p->pNext = pNew;     // p指向新节点 
	pNew->pNext = q;       // 新节点指向后一个节点 
	
	printf("inserteing succeeded!\n");
	return; 
}

void delete_list(PNODE pHead)
{
	int i = 0;
	int pos;
	PNODE p = pHead;
	
	printf("请输入您要删除节点的位置:pos = ");
	scanf("%d", &pos);
	
	while (p->pNext != NULL && i < pos - 1)  //该循环结构使得p总能指向第pos个节点的前一个节点 前提是pos <= len 
	{                                     //p指向的节点的指针域为空时，说明pos位置有误且无法找到该链表最后一个节点 
		p = p->pNext;             // 当pos = len + 1时，退出循环 
		i++;                  
	}
	                     //p最多只能定位到倒数第二个节点处 
	if (i > pos - 1 || p->pNext == NULL)  //阻止用户恶意输入  后者当pos = len +1 时，也会被终止 
	{
		printf("pos输入有误，程序无法执行!\n");
		return;
	} 
	
	PNODE q = p->pNext;
	printf("删除学生%s 成功,其成绩为:%.2f!\n", p->pNext->name, p->pNext->score); 
	p->pNext = p->pNext->pNext; 
	free(q);
	q = NULL; 
	
	return;
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

int length_list(PNODE pHead)
{
	
	int cnt = 0;
	PNODE p = pHead->pNext;
	
	while (p != NULL)
	{
		p = p->pNext;
		cnt++;
	}
	printf("该链表的length = %d\n", cnt);
	return cnt;
}

void sort_list(PNODE pHead, int len)  //通过将节点的数据域的所有成员互换，来达到改变节点先后顺序的排序算法 
{
    int i, j;
	char h[10];
	float t;
    
    PNODE p = pHead->pNext;
	PNODE q = p->pNext;
	
	for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext)  //双条件单循环结构 
	{                                                  //双条件单循环  切记内层循环语句的初始化条件不可遗漏 
		for (j = i + 1, q = p->pNext; j < len ; j++ , q = q->pNext)    //j的初始化条件为: j = i + 1   q=p->pNext的条件不可缺少 
		{
			if (p->score < q->score)
			{
			    t = p->score;
				p->score = q->score;
				q->score = t;
			
				strcpy(h, p->name);   //字符数组的相互赋值，只能通过strcpy函数来实现，不能直接赋值！！！ 
				strcpy(p->name, q->name);  //中间变量字符数组h代表整个字符数组，注意H的代码格式 
				strcpy(q->name, h);
	           		
			}
		}
	}
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
		
		free(p);             //头结点也会被释放，当len=0时， 
		p = pHead->pNext;
		len--;
	}
	
	free(pHead);
	
	while (p != NULL)
	{
		printf("%s 该学生的成绩为:%.2f\n", p->name, p->score);
		
		p = p->pNext;
	}
}
