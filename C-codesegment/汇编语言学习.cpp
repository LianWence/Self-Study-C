#include <stdio.h>

struct company {   //����һ����˾��¼�Ľṹ�� 
	char cn[4];    //��˾���� 
	char hn[10];    //�ܲ����� 
	int pm;        //���� 
	int sr;        //���� 
	char cp[4];    //������Ʒ 
};

main()
{
	struct company dec={"DEC", "Ken Olsen", 137, 40, "PDP"};  //����һ����˾��¼�ı���,�ڴ��н�����һ����˾�ļ�¼
	
	int i;
	dec.pm = 38;
	dec.sr = dec.sr + 70;
	i = 0;
	dec.cp[i] = 'v';
	i++;
	dec.cp[i] = 'A';
	i++;
	dec.cp[i] = 'X';
	printf("�ù�˾�������:\n");
	printf("����:%s\n  ����:%d\n ����:%d \n ��Ʒ:%s\n", dec.cn, dec.pm, dec.sr, dec.cp);
	printf("����:%s\n", dec.hn);
	return 0;
}
 
