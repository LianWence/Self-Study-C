/*
       2015.8.10 10:06 
       ��һԪ���η��̵�ʵ�� 
*/ 

#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, c;
	double x1, x2;
	double delta;
	char ch;
    do	
	{
	    printf ("�밴Ҫ�����������һԪ���η��̵ĸ���ϵ����\n");
	
	    printf ("������:a = ");
	    scanf ("%lf", &a);
	
	    printf ("������:b = ");
	    scanf ("%lf", &b);
	
	    printf ("������:c = ");
	    scanf ("%lf", &c);
	
	    delta = b*b - 4*a*c;
	
	
	
		if (delta > 0)
		{   
		    x1 = (-b + sqrt(delta)) / (2*a);
		    x2 = (-b - sqrt(delta)) / (2*a);
		    printf ("��������:x1 = %lf, x2 = %lf\n", x1, x2);
		}
		else if (0 == delta)
		{
			 x1 = x2 = (-b) / (2*a);
			printf("��һ����:x1 = x2 = %lf\n", x1, x2);
		}   
		else
		     printf ("�÷�����ʵ����\n");	    
		
		printf ("���Ҫ�������밴y������������������˳�:");
		scanf (" %c", &ch);  //�����˻���������ؼ�һ������׼�⺯��scanf�Ŀ��Ʒ�%cǰ������е��пո񣡣���ǧ��ע�⣡ 
		
	} while ('y'==ch || 'Y'==ch);
	
	printf ("лл����ʹ�ã��ټ���\n");
	return 0;
}
/*
   do-whileѭ���ĳɹ�Ӧ��----ʵ���˻�����
   ����scanf��׼�⺯����ʵ���˻������Ĺؼ�һ�������Ʒ�%cǰ��Ҫ���Ͽո���ϸ�ο�  �������ġ�C Primer Plus��
   �Ȿ��������ϸ�����˿հ׷������⡣ 

*/ 


