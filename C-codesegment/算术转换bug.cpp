//  2016.3.9    10:28    ����C�����е�����ת����BUG 

#include <stdio.h>
#include <string.h>

int array[] = {23, 34, 12, 17, 204, 99, 16};
#define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))  //sizeof����  Ĭ�Ϸ���ֵΪ�޷�������----unsigned int���� 

int main(void)
{
	int d = -1; 
	int x;

	if (d <= (int)(TOTAL_ELEMENTS - 2))	  //�����ֶ�ǿ������ת�� ���߱�����Ҫת����ʡô���͵����� 
//	if (d <= (TOTAL_ELEMENTS - 2)) //d = -1��ֵ��������������ת��Ϊ�޷�������,-1�ᱻת����һ���ܴ������  ���ж�����Ϊ�� 
	{	
		printf("####����ֵ:23\n");
		x = array[d + 1];
		printf("****ʵ��ֵ: %d\n", x); 
	}
	else
		printf("����ת������!\n");
	return 0;
}

//  �мǲ�Ҫ����,�����޷������͵�����,�������Ӳ���Ҫ�ĸ����� 
