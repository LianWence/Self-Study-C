/*
                           2015.8.11  13:45
           ͨ��������������������----��1��ĳ����֮������Ϊ��������������� 
*/

#include <stdio.h> 

void output(int val);  //���������������Ǻ���ԭ�� 
bool IsPrime(int i);   //���������������Ǻ���ԭ�� 

int main()
{
	int val;
	int i, j;
	
	j = 0;
	
	printf("�����������жϵ�������ı߽�ֵ��");
	scanf("%d", &val);
	
	printf("2��%d֮����������Ϊ��\n", val);
	
	output(val);
	
	
	
	return 0;
}

  //  �����������ǣ��Դ�1��ĳ����֮������Ϊ���������������ӡ������ 
void output(int val)
{
	int i;
	int j = 0; 
	
	for (i = 2; i < val; i++)
	{
		if (IsPrime(i))
		{
		    printf("%d\t", i);
	        j++;
	        if (j % 5 == 0)   //�����Ƹ�����еı��ʽĿ����Ϊ�˱�֤ÿ��ֻ��ӡ��5������������ 
	            printf("\n");
        }  
	} 
	
}

//  �����������ǣ� �ж�i�ǲ����������ǵĻ�������true�����򷵻�false�� 
bool IsPrime(int i) 
{
	int j;
	
    for (j = 2; j < i; j++)
    {
        if (i % j == 0)
		    break;
    } 
	if (i == j)
	    return true;
	else
	    return false;			 
}
