
/*
                      2015.8.11   10:16             
            ͨ���û��Զ��庯����Ϊ�������������ж�һ�����ǲ������� 
*/ 

#include <stdio.h>

bool IsPrime(int val)  //bool ΪC�����е����������ͣ���ֻ��������true������false���ֱ��Ӧ����ֵΪ1��0�� 

{
	int i;
	
	for (i = 2; i < val ; i++)
	{
		if (val % i == 0)     //���������Ķ��壬�ȼ�������һ������������ܱ�2�͸�������һ����֮���������������������Ϊ0������ô����Ϊ������ 
	        break;
	}
    if (i == val)
        return true;    //return���ִ����Ϻ󣬻���ֹ�ñ��������� ����true��Ӧ����ֵΪ1�� 
    else
	    return false;   //����false��Ӧ����ֵΪ0����bool�������͹涨��    
} 

int main(void)

{
	int prime;
  	
  	printf("����������һ�������жϵ�����:");
  	scanf("%d", &prime);
  	
	if (IsPrime(prime))  //���ʽ���㼴Ϊ�棬��Ϊ�٣� ͬʱ��return��佫ֵ���ص������ú�������Ҳ���Ǵ˴��� 
	    printf("����Ϊ����\n");
	else 
        printf("������������\n");	
	
	return 0;
}
