/*
          2015.8.24      19:19
        链式二叉树的代码    
*/
#include <stdio.h>
#include <malloc.h>

typedef struct PTNode
{
	char ch;
	struct PTNode *PLchild;
	struct PTNode *PRchild;
}PN, *PNE;

PNE createbtree(void);
void Preterversebtree(PNE);
void Interversebtree(PNE);
void Postterversebtree(PNE);

int main(void)
{
	PNE pT = createbtree();  //动态返回该二叉树的根节点的地址 
	Preterversebtree(pT);
	Interversebtree(pT);
	Postterversebtree(pT);
	
	return 0;
}

PNE createbtree(void)
{
	PNE pA = (PNE)malloc(sizeof(PN));  //动态构造出A节点
	PNE pB = (PNE)malloc(sizeof(PN));
	PNE pC = (PNE)malloc(sizeof(PN));
	PNE pD = (PNE)malloc(sizeof(PN));
	PNE pE = (PNE)malloc(sizeof(PN));

    pA->ch = 'A';
    pB->ch = 'B';
    pC->ch = 'C';
    pD->ch = 'D';
    pE->ch = 'E';
    
    pA->PLchild = pB;
    pA->PRchild = pC;
    pB->PLchild = pB->PRchild = NULL;
    pC->PLchild = pD;
    pC->PRchild = NULL;
    pD->PLchild = NULL;
    pD->PRchild = pE;
    pE->PLchild = pE->PRchild = NULL;
	
	return pA; 
}

void Preterversebtree(PNE pT)
{
	/*
      先访问根节点
	  再先序访问左子树 
	  再先序访问右子树 
	*/
	if (pT != NULL)
	{
		printf("%c\n", pT->ch);  //先访问根节点
		Preterversebtree(pT->PLchild);//再先序访问左子树 
		Preterversebtree(pT->PRchild);//再先序访问右子树 
	}
	return;	
}

void Interversebtree(PNE pT)  //中序遍历 
{
	if (pT != NULL)
	{
		Interversebtree(pT->PLchild);//先中序访问左子树 
		printf("%c\n", pT->ch);  //再访问根节点
		Interversebtree(pT->PRchild);//再中序访问右子树 
	}
	
	return;
}

void Postterversebtree(PNE pT)
{
	if (pT != NULL)
	{
		Postterversebtree(pT->PLchild);//先后序访问左子树 
		Postterversebtree(pT->PRchild);//再后序访问右子树 
		printf("%c\n", pT->ch);    //再访问根节点 
	}
}
