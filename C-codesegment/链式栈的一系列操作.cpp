/*
               2015.8.21   12:24
          对链式栈执行初始化，压栈，出栈，遍历等一系列的操作 
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
	float score;           //数据域 
	char name[10];          //数据域 
	struct node *pNext;  //指针域 
}NODE, *PNODE;

typedef struct stack
{
	PNODE pTop;   //栈顶指针 
	PNODE pBottom;   //栈底指针 
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

void initialize_stack(PSTACK pS)    //初始化链式栈，即让pTop和pBottom相等 
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));    //动态构造一个名义上的“头结点” 
	
	if(pS->pTop == NULL)
	{
		printf("内存分失败，程序即将终止!\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;               //两指针均指向同一个节点的位置 
	    pS->pBottom->pNext = NULL;            //两指针指向的同一个节点的指针域为空，类似于链表中的头结点 
	}
	return; 
}

void push_stack(PSTACK pS)   // 进行压栈 
{
	char ch;
	
	do
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));  //动态构造有效节点，并将首字节地址返回给指针pNew
		
		pNew->pNext = pS->pTop; //默认新构造的节点指向下一个节点即指针域保存下面节点的地址
		pS->pTop = pNew; //pTop永远指向栈顶节点，所以pTop要保存新节点的地址 
		            //对新构造节点的数据域进行赋值 
		printf("----请输入学生姓名:name = ");
		scanf("%s", pNew->name);    // 因为成员中字符数组名本身就是地址，所以不需要加取地址符号& 
		printf("----请输入该学生成绩:score = ");
		scanf("%f", &pNew->score);
		 
	    printf("( ****继续:Y/y  退出:其他任意键****):");
		scanf(" %c", &ch);	 
	} while (ch == 'Y' || ch == 'y');
	
	return;
}  

void traverse_stack(PSTACK pS)        //遍历该链式栈，从上往下依次输出 
{
	PNODE r = pS->pTop;
	
	printf("#####遍历后的结果为:\n");
	while (r != pS->pBottom)     //撤了栈底节点不输出外，其余有效节点全部输出 
	{
		printf("学生:%-5s ------ 成绩:%3.2f \n ", r->name, r->score);
		r = r->pNext;   //r再次指向下一个节点 
	}
	return;
}

void pop_stack(PSTACK pS)    //   将有效节点进行出栈 
{
	char ch;
	
	if (is_empty(pS))
	{
		printf("++++该链式栈为空，程序无法执行出栈++++\n");
		return; 
	}
	else
	{
		PNODE r = pS->pTop;
		printf("^-^程序正在执行出栈^-^\n");
		
		do
		{
			printf("****学生:%-5s 成绩:%3.2f####出栈成功****\n", r->name, r->score);
			pS->pTop = r->pNext;     //pTop 指向下一个栈顶节点 
			free(r);   // 将r指向的节点出栈 
		    r = pS->pTop;  //r再次指向栈顶节点 
		    
		    printf("^+^继续出栈:Y/y 退出:其它任意键^+^:");
		    scanf(" %c", &ch);
		}while (r != pS->pBottom && (ch == 'Y' || ch == 'y'));   //继续循环的前提是r不能等于pBottom，且用户输入了Y或y 
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

void release_stack(PSTACK pS)   //释放动态内存 
{
	PNODE q;
	PNODE r = pS->pTop;  
	
	while (r != NULL)
	{
		q = r->pNext;   //指针变量q永远指向r指向节点的下面那一个节点
		free(r);
		r = q;    //指针变量r再次指向下一个节点 
	}
	 
	traverse_stack(pS);  //检查动态内存是否释放成功 
	
	return;
}
