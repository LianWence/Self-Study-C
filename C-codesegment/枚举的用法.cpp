
/*
                   2015.8.15  0:20   ��д��һ���鿴���Ƶ�С���� 
              ö�ٵ��÷���ö�ٱ�֤�˴���İ�ȫ�ԣ���ʹ�ô���ı�д��Ϊ�鷳 
*/
#include <stdio.h>

enum weekday 
{
	monday=1, tuesday, wednesday, thursday, friday, saturday, sunday
}; // ������һ��ö����������enum weekday  ���о��������п��ܴ洢��ֵ��Ԫ��Ҳ�У� 

void output(enum weekday );

int main(void)
{
	enum weekday day = wednesday;
	
	output(day);
	
	return 0;
}

void output(enum weekday what)
{
	switch (what)
	{
		case 1:
			printf("����������ܰ���\n");
			break;
		case 2:
		    printf("������»����һ��ˣ�\n");
			break;
		case 3:
		    printf("��������һ�㣡\n");
			break;
		case 4:
		    printf("�������ƽ������Ҹ�ָ�����ջ\n");
			break;
		case 5:
		    printf("���첻�ʺ���潣�ע�����壡\n");
		    break;
		case 6:
		    printf("�����Ǹ������ӣ�����ȥ������\n");
		    break;
		case 7:
		    printf("����ߣ��Ҫ���ף�ף���Ը����֣�\n");
			break;						
	}
}
