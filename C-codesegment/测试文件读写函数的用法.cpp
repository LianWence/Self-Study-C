/*
       2015.8.29   22:37
      �����ļ���д����fputc()��fgetc()���÷� 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char ah;
	char ch = 'm';
	
	if (fp = fopen("F:\\�������ļ�\\a.txt", "w+")) //�ļ��򿪳ɹ�:�������ظ��ļ��ĵ�ַ�����򷵻�NULL 
	{
		printf("^_^�ļ��򿪳ɹ�!\n");
		
		if (fputc(ch, fp) == EOF) //�ļ���д����ԭ��:int fputc(int c, FILE *fp)  ���Ҫ�����ַ����ǵ�Ҫ�ӵ����š��� 
		{                           //�ú���������ɹ�ִ�У�����ֵΪc������ΪEOF���ļ��������� 
			printf("~_~����д��ʧ��!\n");       
			exit(0);
		}
		else
		{
			printf("^_^����%cд��ɹ�!\n", fputc(ch, fp));
			
			if ((ah = fgetc(fp)) != EOF)  //�ļ���д����ԭ��:int fgetc(FILE *fp) �ú����Ĺ�����:��fpָ����ļ��ж�ȡһ���ֽڴ��룬��д�뵽���ļ��� 
			{                            //��ȡ��д��ɹ�֮�󣬷�������ȡ�Ĵ��룻���򣬷���EOF���������ļ���βʱ������ֵ��ͬ�� 
				printf("**** %c�����ȡ�ɹ�****\n", ah);
				
				if (fclose(fp))
				{
					printf("�ļ��ر�ʧ�ܣ�\n");
				}
				else
					printf("�ļ��رճɹ�!\n");
			}
			else
				printf("~_~��ȡʧ��\n");
		}
	}
	else
	{
		printf("�ļ���ʧ��");
		exit(0);
	}
	
	return 0;
}
/*
       fgetc()�����Ĺ����ǽ����ļ��ж�ȡ��һ�ֽڴ�����д�뵽�ļ���ȥ 

*/
