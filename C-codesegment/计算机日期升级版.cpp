//2016.2.28  16:24  ���������������  
#include <stdio.h>
#include <time.h>   

int main()
{
	time_t biggest = 0x7FFFFFFF;  //time_t �� long��typedef��ʽ
	
	printf("biggest = %s \n", asctime(gmtime(&biggest)));	 //gmtime() �������𽫲���ת��������������(UTC)ʱ��ֵ  ���Ǹú���������һ���ɴ�ӡ���ַ��� 
															//asctime() �������𽫻�ȡ gmtime()���� ת������ʱ��ֵ 
	return 0;
}
