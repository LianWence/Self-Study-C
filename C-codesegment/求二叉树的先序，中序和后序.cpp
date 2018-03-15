/*
          2015.8.24      19:19
        ��ʽ�������Ĵ���    
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
	PNE pT = createbtree();  //��̬���ظö������ĸ��ڵ�ĵ�ַ 
	Preterversebtree(pT);
	Interversebtree(pT);
	Postterversebtree(pT);
	
	return 0;
}

PNE createbtree(void)
{
	PNE pA = (PNE)malloc(sizeof(PN));  //��̬�����A�ڵ�
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
      �ȷ��ʸ��ڵ�
	  ��������������� 
	  ��������������� 
	*/
	if (pT != NULL)
	{
		printf("%c\n", pT->ch);  //�ȷ��ʸ��ڵ�
		Preterversebtree(pT->PLchild);//��������������� 
		Preterversebtree(pT->PRchild);//��������������� 
	}
	return;	
}

void Interversebtree(PNE pT)  //������� 
{
	if (pT != NULL)
	{
		Interversebtree(pT->PLchild);//��������������� 
		printf("%c\n", pT->ch);  //�ٷ��ʸ��ڵ�
		Interversebtree(pT->PRchild);//��������������� 
	}
	
	return;
}

void Postterversebtree(PNE pT)
{
	if (pT != NULL)
	{
		Postterversebtree(pT->PLchild);//�Ⱥ������������ 
		Postterversebtree(pT->PRchild);//�ٺ������������ 
		printf("%c\n", pT->ch);    //�ٷ��ʸ��ڵ� 
	}
}
