/*
       2015.8.10  13:13
       ����switch����ѡ��ṹʵ��ʹ�õ��ݵļ��׳���! 
*/
#include <stdio.h>
int main(void)
{
	int val;
	char ch, c;
	
	do
	{ 
	
	    printf ("���������뵽���¥�㣺");
	    scanf ("%d", &val);
	
	    while ((c=getchar()) != '\n')
	         continue; 
	    
	    switch (val)
	    {
		    case 1:  // case���治���Ǹ��������ʽ������ֵ����ֻ����Ψһ��һ����������������������� 
			    printf ("���ڵ����%d��\n", val);
			    break;
		    case 2:
		        printf ("���ڵ����%d��\n", val);
			    break;
		    case 3:
		        printf ("���õ�%d������ά���У�����ѡ��ͽ���¥�㡣�����������㣬���½�\n", val);
			    break;
		    case 4:
		        printf ("���ڵ����%d��\n", val);
			    break;
		    case 5:
		        printf ("����,��¥�㻹���½��У�������ʱ�޷�ʹ�ã���Ǹ\n");
			    break;
		    default :
		        printf ("���ã���¥��Ŀǰֻ��5�㣡���в��㣬������£�\n");
			    break;				
		}
	printf ("�������Ҫ�������룬�밴��y����Y�����ɣ���������������˳�ʹ�ã�");
	scanf (" %c", &ch);     //ע����Ʒ�%Cǰ��Ҫ���пո�����հ׷��������ش��ڴ˲������ۡ� 
    } while ( 'y'==ch || 'Y'==ch );    //�ٴ�ʹ��do-whileѭ���ṹʵ���˻������� 
	
	printf ("���ã���ӭ�������ε��ݣ�ף��������죡\n");
	
	return 0;
}
/*
    ��֤switch��ѡ�ṹ���÷����ܿ��ģ����� 
*/

