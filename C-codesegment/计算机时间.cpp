//2016.2.28   16:13   ���ʵ�ּ���������� 
#include <stdio.h>
#include <time.h>  //����ȱ�ٵ�ͷ�ļ� 

int main()
{
	//time_t biggest = 0x7FFFFFFF;   //��C������time_t  �� long��typedef��ʽ 
	long biggest = 0x7FFFFFFF; 
	
	printf("biggest = %s \n", ctime(&biggest));  //ctime()  ��������ʮ�����Ʋ���ת���ɵ���ʱ��   �˴�ָ���������� 
	return 0;
} 
