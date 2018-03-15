/*
                         2015.8.23   9:01
              用递归思想解决汉诺塔问题        后调用先返回 
*/
#include <stdio.h>

void hannuota(int , char , char , char);

int main(void)
{
	char A, B, C;   //先将三根柱子定义出来 
	int n;      //盘子数
	
	printf("请输入盘子数:n = ");
	scanf("%d", &n);
	
	hannuota(n, 'A', 'B', 'C');  
	
	return 0; 
}

void hannuota(int n, char A , char B, char C)
{
	if (n == 1)
	{
		printf("将第%d个盘子直接从%c放到%c\n", n, A, C);
	}
	else
	{
		hannuota(n - 1, A, C, B);           //先将A柱子上的n-1个盘子借助C放到B上面来  很复杂 
		printf("将第%d个盘子直接从%c放到%c\n", n, A, C);  //再将第n个盘子从A直接放到C上面来 
		hannuota(n - 1, B, A, C);   //新的开始，再将第n-1个盘子从B柱子借助A柱子移到C柱子上  任务很复杂，但逻辑上已经完成 
	}
}
