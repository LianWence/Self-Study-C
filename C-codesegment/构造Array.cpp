/*
              2015.8.18  22.38
         �����Դ洢�����Ӧ�� 
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> //����exit������ͷ�ļ� 

struct Array
{
	int *Pbase;    //   �����е�һ��Ԫ�صĵ�ַ 
	int len;       //   ����ĳ��� 
	int cnt;       //   ������Ԫ��Ϊ��Чֵ�ĸ��� 
};

void initialize_array(struct Array *, int );   //��ʼ���ö�̬�ڴ� 
void append_array(struct Array *);   //׷��Ԫ�� 
void insert_array(struct Array *); //�������в���ĳ��ֵ
void delete_array(struct Array *);  //ɾ����������ĳ��Ԫ�� 
void inversion_array(struct Array *);   //������������е��� 
void sort_array(struct Array*);   //�����������Ԫ�ؽ���ð������ 
bool is_full(struct Array *);    //�жϸ�������ЧԪ�ظ����Ƿ��ѵ���length 
bool is_empty(struct Array *);        //�жϸ������Ƿ�Ϊ�� 
void show_array(struct Array *);   //����������е���ЧԪ�ص�ֵ 
void check_array(struct Array *);  //��鶯̬�ڴ��Ƿ��ͷ���� 

int main(void)
{
	struct Array arr;
    int length;
	
	printf("����������Ϊ����������Ԫ�ظ���:");
	scanf("%d", &length);

    initialize_array(&arr, length);
    append_array(&arr);
    insert_array(&arr);
    delete_array(&arr);
    inversion_array(&arr);
	show_array(&arr);
	check_array(&arr); //����Ƿ��ͷųɹ� 
	
	return 0;
} 

void initialize_array(struct Array *pArray, int length)
{
	pArray->Pbase = (int *)malloc(sizeof(struct Array) * length);  //��ԱPbase����������Ϊint *  �˴����Գ�ԱPbaseΪ���� 
	
	if (NULL == pArray->Pbase)
	{
		printf("��̬�ڴ�ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}
	else
	{
		pArray->len = length;
		pArray->cnt = 0;
	}
	return;   //�������˴˺�����д����� 
}

void append_array(struct Array *pArray)
{
	int val;
	char s;
	
	if (pArray->cnt == pArray->len)
    {
	    printf("׷��ʧ�ܣ�������ֹ\n");
	    exit(-1); //��ֹ����   ����return���Ҳ���� 
	}
	while(pArray->cnt < pArray->len)
	{
		printf("����������׷�ӵ�ֵ:");
		scanf("%d", &val);
		pArray->Pbase[pArray->cnt] = val;
		pArray->cnt++;
		printf("���Ƿ���Ҫ����׷��(��Y��y����������������˳�):");
		scanf(" %c", &s);   //���Ʒ�ǰ����пհ׷�������������Ҫ 
		if (s == 'Y' || s == 'y')     //�û�����������getchar()���������,�������˳��ִ�� 
		    continue;                                         //scanf���Ʒ������Ҫ��һ���հ׷����� 
		else
		    break;    
	}
	printf("׷��Ԫ�سɹ�!!\n");
	return;
} 
 
void insert_array(struct Array *pArray)
{
	int pos, val, i;
	char c;
	
	printf("����ִ�жԸ�����Ĳ������:\n");
	printf("������pos = ");
	scanf("%d", &pos);
	printf("������val = ");
	scanf("%d", &val);

	if (is_full(pArray))
	{
		printf("����������,���򼴽���ֹ!\n");
		exit(-1);
	}
	else if (pos < 1 || pos > pArray->cnt + 1)  //�����еĴ洢�м�Ԫ�ز����п�ֵ���������л��������д��pArray->len+1 
	{                                           //���������һ�������洢�����м�Ԫ�ز��ǿ�ֵ 
		printf("��������,���򼴽���ֹ!\n");
		exit(-1);
	}
	
	for (i = (pArray->cnt - 1); i >= pos - 1; i--)  //ִ������Ϊi>=pos-1  д��С�ںż�ʹ����������ѭ��  �������г��� 
	    pArray->Pbase[i + 1] = pArray->Pbase[i];   
	    
	pArray->Pbase[pos - 1] = val;
	pArray->cnt++;
    printf("inserting succeeded!!\n");
}
  
void delete_array(struct Array *pArray)  //ɾ��������ĳһλ�õ�Ԫ�� 
{
	int pos, val;
	
	if (is_empty(pArray))
	{
		printf("������Ϊ�գ����򼴽���ֹ\n");
		exit(-1);
	}
	else
	{
	
	printf("��������Ҫɾ��Ԫ�ص�λ��:pos = ");
	scanf("%d", &pos);
	
	val = pArray->Pbase[pos - 1];
	printf("ɾ��Ԫ�سɹ�����Ԫ�ص�ֵΪ:%d\n", val);
	
	for (int i = pos; i < pArray->cnt; i++) //�Ǳ�ɾ��Ԫ�ص�λ�ú����Ԫ�ظ���ǰ��ľͿ�����,�ظ�ֱ�����һ��Ԫ�ؾͿ����� 
	    pArray->Pbase[i - 1] = pArray->Pbase[i];
    pArray->cnt--;
	}
}

void inversion_array(struct Array *pArray)  //���������ЧԪ�ؽ��е��� 
{
	int i, j, t;
	
	i = 0;               //iΪ�����е�һ��Ԫ�ص��±�    
	j = pArray->cnt - 1;  //jΪ���������һ��Ԫ�ص��±� 
	
	while (i < j)   
	{
		t = pArray->Pbase[i];
		pArray->Pbase[i] = pArray->Pbase[j];
		pArray->Pbase[j] = t;   //�������е�i��Ԫ�ظ�������i��Ԫ�ؽ���,ѭ��������i < j(������i��ֵ)
		
		i++;
		j--; 
	}
	printf("���óɹ�!!\n");
}

void sort_array(struct Array *pArray)
{
	int i, j, t;
	
	if (is_empty(pArray))
	{
		printf("������Ϊ�գ����򼴽���ֹ\n");
		exit(-1);
	}
	else
	{
		for (i = 0; i < pArray->cnt - 1; i++)
		{
			for (j = i + 1; j < pArray->cnt; j++)
			{
				if (pArray->Pbase[i] > pArray->Pbase[j])
				{
					t = pArray->Pbase[i];
					pArray->Pbase[i] = pArray->Pbase[j];
					pArray->Pbase[j] = t;
				}
			} 
		}
	}
	printf("ð������ɹ�\n");
}

bool is_full(struct Array *pArray)  //�жϸ������ǲ��Ǵ洢���� 
{
	if (pArray->cnt == pArray->len)
	    return true;
	else
	    return false;	 
}

bool is_empty(struct Array *pArray)   //�ж������Ƿ�Ϊ�� 
{
	if (pArray->cnt == 0)
	    return true;   //����ֵΪ1 
	else    
	    return false;  //����ֵΪ0 
}

void show_array(struct Array *pArray)  //�����������ЧԪ�ص�ֵ��ӡ����Ļ�� 
{
	if (is_empty(pArray))
	{
		printf("�������Ԫ��Ϊ�գ��޷����\n");
		exit(-1);
	}
	else
	{
		printf("����������ЧԪ�ص�ֵΪ:\n");
		for(int i = 0; i < pArray->cnt; i++)   //ִ�������ǣ�i < pArray->cnt ���� ��ΪҪ�����ЧԪ�ص�ֵ 
		{
			printf("%d\t", pArray->Pbase[i]);
		}
		printf("\n");
	}
}

void check_array(struct Array *pArray) //��鶯̬�ڴ��Ƿ��ͷųɹ� 
{
	for(int j = 0; j < pArray->len; j++ )  
	    free(pArray->Pbase + j);  //�ͷŸö�̬�ڴ� 
	
	printf("��̬�ڴ��ͷź�����Ϊ:\n");
	
	for(int i = 0; i < pArray->len; i++)
	    printf("%d\t", pArray->Pbase[i]);
}
/*
     ���û����н���ʱ������ͨ��scanf�����ڿ��Ʒ���ǰ�桿����һ���հ׷�����ɻ���ͨ��gerchar��������ɶ��ַ������� ������
	 ������ͨ��ʱ������ָ�ó���û���﷨���󡣵������������й����У�Ī���������ֹʱ��˵�������е�ĳЩ�жϱ��ʽ����
	ѭ�����ʽ�߼����󣬱���˵>�ű���С�ĸ�д��<����,���ִ�����ѱ����֣������� 
	  
*/ 



