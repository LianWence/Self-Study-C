/*
              2015.8.18  22.38
         对线性存储数组的应用 
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> //包含exit函数的头文件 

struct Array
{
	int *Pbase;    //   数组中第一个元素的地址 
	int len;       //   数组的长度 
	int cnt;       //   数组中元素为有效值的个数 
};

void initialize_array(struct Array *, int );   //初始化该动态内存 
void append_array(struct Array *);   //追加元素 
void insert_array(struct Array *); //在数组中插入某个值
void delete_array(struct Array *);  //删除该数组中某个元素 
void inversion_array(struct Array *);   //对现有数组进行倒置 
void sort_array(struct Array*);   //对现有数组的元素进行冒泡排序 
bool is_full(struct Array *);    //判断该数组有效元素个数是否已到达length 
bool is_empty(struct Array *);        //判断该数组是否为满 
void show_array(struct Array *);   //输出该数组中的有效元素的值 
void check_array(struct Array *);  //检查动态内存是否释放完毕 

int main(void)
{
	struct Array arr;
    int length;
	
	printf("请输入您想为该数组分配的元素个数:");
	scanf("%d", &length);

    initialize_array(&arr, length);
    append_array(&arr);
    insert_array(&arr);
    delete_array(&arr);
    inversion_array(&arr);
	show_array(&arr);
	check_array(&arr); //检查是否释放成功 
	
	return 0;
} 

void initialize_array(struct Array *pArray, int length)
{
	pArray->Pbase = (int *)malloc(sizeof(struct Array) * length);  //成员Pbase的数据类型为int *  此处是以成员Pbase为主体 
	
	if (NULL == pArray->Pbase)
	{
		printf("动态内存失败，程序终止！\n");
		exit(-1);
	}
	else
	{
		pArray->len = length;
		pArray->cnt = 0;
	}
	return;   //告诉他人此函数编写已完成 
}

void append_array(struct Array *pArray)
{
	int val;
	char s;
	
	if (pArray->cnt == pArray->len)
    {
	    printf("追加失败，程序终止\n");
	    exit(-1); //终止程序   换成return语句也可以 
	}
	while(pArray->cnt < pArray->len)
	{
		printf("请输入您想追加的值:");
		scanf("%d", &val);
		pArray->Pbase[pArray->cnt] = val;
		pArray->cnt++;
		printf("您是否想要继续追加(按Y或y继续，其它任意键退出):");
		scanf(" %c", &s);   //控制符前面得有空白符！！！！很重要 
		if (s == 'Y' || s == 'y')     //用户输入必须得由getchar()函数来完成,程序可以顺利执行 
		    continue;                                         //scanf控制符语句中要有一个空白符才行 
		else
		    break;    
	}
	printf("追加元素成功!!\n");
	return;
} 
 
void insert_array(struct Array *pArray)
{
	int pos, val, i;
	char c;
	
	printf("即将执行对该数组的插入操作:\n");
	printf("请输入pos = ");
	scanf("%d", &pos);
	printf("请输入val = ");
	scanf("%d", &val);

	if (is_full(pArray))
	{
		printf("该数组已满,程序即将终止!\n");
		exit(-1);
	}
	else if (pos < 1 || pos > pArray->cnt + 1)  //数组中的存储中间元素不能有空值，否则运行会出错！不能写成pArray->len+1 
	{                                           //数组必须是一段连续存储的且中间元素不是空值 
		printf("输入有误,程序即将终止!\n");
		exit(-1);
	}
	
	for (i = (pArray->cnt - 1); i >= pos - 1; i--)  //执行条件为i>=pos-1  写成小于号即使程序陷入死循环  甚至运行出错 
	    pArray->Pbase[i + 1] = pArray->Pbase[i];   
	    
	pArray->Pbase[pos - 1] = val;
	pArray->cnt++;
    printf("inserting succeeded!!\n");
}
  
void delete_array(struct Array *pArray)  //删除数组中某一位置的元素 
{
	int pos, val;
	
	if (is_empty(pArray))
	{
		printf("该数组为空，程序即将终止\n");
		exit(-1);
	}
	else
	{
	
	printf("请输入您要删除元素的位置:pos = ");
	scanf("%d", &pos);
	
	val = pArray->Pbase[pos - 1];
	printf("删除元素成功，该元素的值为:%d\n", val);
	
	for (int i = pos; i < pArray->cnt; i++) //是被删除元素的位置后面的元素覆盖前面的就可以了,重复直至最后一个元素就可以了 
	    pArray->Pbase[i - 1] = pArray->Pbase[i];
    pArray->cnt--;
	}
}

void inversion_array(struct Array *pArray)  //对数组的有效元素进行倒置 
{
	int i, j, t;
	
	i = 0;               //i为数组中第一个元素的下标    
	j = pArray->cnt - 1;  //j为数组中最后一个元素的下标 
	
	while (i < j)   
	{
		t = pArray->Pbase[i];
		pArray->Pbase[i] = pArray->Pbase[j];
		pArray->Pbase[j] = t;   //让数组中第i个元素跟倒数第i个元素交换,循环条件是i < j(倒数第i的值)
		
		i++;
		j--; 
	}
	printf("倒置成功!!\n");
}

void sort_array(struct Array *pArray)
{
	int i, j, t;
	
	if (is_empty(pArray))
	{
		printf("该数组为空，程序即将终止\n");
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
	printf("冒泡排序成功\n");
}

bool is_full(struct Array *pArray)  //判断该数组是不是存储已满 
{
	if (pArray->cnt == pArray->len)
	    return true;
	else
	    return false;	 
}

bool is_empty(struct Array *pArray)   //判断数组是否为空 
{
	if (pArray->cnt == 0)
	    return true;   //返回值为1 
	else    
	    return false;  //返回值为0 
}

void show_array(struct Array *pArray)  //将该数组的有效元素的值打印到屏幕上 
{
	if (is_empty(pArray))
	{
		printf("该数组的元素为空，无法输出\n");
		exit(-1);
	}
	else
	{
		printf("该数组中有效元素的值为:\n");
		for(int i = 0; i < pArray->cnt; i++)   //执行条件是：i < pArray->cnt 即可 因为要输出有效元素的值 
		{
			printf("%d\t", pArray->Pbase[i]);
		}
		printf("\n");
	}
}

void check_array(struct Array *pArray) //检查动态内存是否释放成功 
{
	for(int j = 0; j < pArray->len; j++ )  
	    free(pArray->Pbase + j);  //释放该动态内存 
	
	printf("动态内存释放后的情况为:\n");
	
	for(int i = 0; i < pArray->len; i++)
	    printf("%d\t", pArray->Pbase[i]);
}
/*
     与用户进行交互时，可以通过scanf函数在控制符【前面】加上一个空白符来完成或者通过gerchar函数来完成对字符的输入 都阔以
	 当编译通过时，就是指该程序没有语法错误。但当程序在运行过程中，莫名其妙地终止时，说明程序中的某些判断表达式或者
	循环表达式逻辑有误，比如说>号被不小心给写成<号了,这种错误很难被发现！！！！ 
	  
*/ 



