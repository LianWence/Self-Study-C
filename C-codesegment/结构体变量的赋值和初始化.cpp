/*
           2015.8.14  10:57
         �Խṹ������ĸ�ֵ����ʼ������� 
*/
#include <stdio.h>

struct TV  //����һ���ṹ����ΪTV�ĸ����������ͣ������µĶ������������϶��� 
{
	int price;
	float size;
	char color;
} ;

int main()
{
	struct TV store = {1000, 15.6, 'Y'};   //�ڶ���ṹ�����store��ͬʱ���г�ʼ�� ,���������帳ֵ 
	
	struct TV store1;
	store1.price = 15000;
	store1.size = 17.3;
	store1.color = 'B';  //�����ȶ��壬Ȼ���ٶԸýṹ���еĻ�������һһ��ֵ�����ֱȽ��鷳�������飡 
	
	printf("��TV����ϢΪ��price = %d, size = %f, color = %c\n", store.price, store.size, store.color);
	printf("��TV����ϢΪ��price = %d, size = %f, color = %c\n", store1.price, store1.size, store1.color);
	                       // ע�����ʱ��printf������ʵ�α���Ϊ���ýṹ���еĻ������ͱ�����ע��Ҫ��д��ȷ 
	return 0;
}
