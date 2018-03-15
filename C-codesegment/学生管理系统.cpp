/*
              2015.8.14  23:32
              简单的学生管理系统 
*/
#include <stdio.h>
#include <malloc.h>

void input(struct student *, int );
void order(struct student *, int );
void output(struct student *, int );

struct student 
{
	float math;
	char name[6];
	int grade;
}; 

int main(void)
{
	int len;
	struct student *pArr;
	
	printf("请输入学生的个数：");
	scanf("%d", &len);
	pArr = (struct student *)malloc(sizeof(struct student) * len); //构造动态一维结构体数组 
	
	input(pArr, len); //pArr = &pArr[0]  将一维动态数组的首个元素的地址和长度传递过去  
	order(pArr, len);
	output(pArr, len);//如此形参都为一级指针就可以了，形参也好定义了 
	
	printf("动态内存释放之前的情况：\n");
	printf("姓名:%s   班级:%d   成绩:%6.2f\n", pArr[0].name, pArr[0].grade, pArr[0].math);
	free(pArr);
	printf("动态内存释放后的情况：\n");
	printf("姓名:%s   班级:%d   成绩:%4.2f\n", pArr[0].name, pArr[0].grade, pArr[0].math); 
	
	return 0;
}

void input(struct student *q, int len)
{
	int i;
	
	printf("请依次输入各学生的信息：\n");
	for (i = 0; i < len; i++)
	{
		printf("第%d个学生的信息为：\n", (i + 1));
		printf("数学成绩: ");
		scanf("%f", &q[i].math);   //因为q=pArr 一起指向那个动态一维数组的第一个元素的首字节地址 
		printf("名字为：");
		scanf("%s", q[i].name);  //该结构体成员中的name为字符数组名，即地址。所以实参不需要再加上取地址符& 
		printf("班级为：");
		scanf("%d", &q[i].grade);
	} 
} 

void order(struct student *q, int len)
{
	int i, j;
	struct student t;
	
	for (i = 0; i < len - 1 ; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (q[i].math < q[j].math)   //<按降序排列 ，>按升序排列 
			{
				t = q[i];
				q[i] = q[j];
				q[j] = t;   //只是交换一下位置，不是交换一下该结构体中的成员值，那么会造成信息混乱不堪，对不上号了 
			}
			
		}
	}
} 

void output(struct student *q, int len)
{
	int i;
	
	printf("按成绩排名的结果为：\n");
	for (i = 0;i < len; i++)
	{
		printf("姓名:%s   班级:%d   成绩:%4.2f\n", q[i].name, q[i].grade, q[i].math); //q=pArr 即q也指向该结构体一维动态数组 
	}
}
