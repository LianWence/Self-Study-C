/*
      2015.8.30         0:26
      ��ָ�����ļ����ݶ�ȡ������ֱ���ļ����ݽ��� 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char ch;
	char *filename = "F:\\�������ļ�\\test.txt";
	
	if ((fp = fopen(filename, "r")) == NULL)    //w���ļ��򿪷�ʽ�Ǹ���ԭ�е��ļ�����������һ���µĿ��ı��ļ� ���˴�ֻ��Ϊr 
	{
		printf("~_~�ļ���ʧ��!\n");
		exit(0);  //�ȼ���return 0�� ���� return�� 
	}
	
	ch = fgetc(fp);  //���Ӹ��ļ��ж�ȡ�Ĵ����ַ���ŵ�����CH�У��Թ�whileѭ���ж�
	while (ch != EOF)
	{
		putchar(ch);  //�����ļ�������һ��һ���ֽڽ������
		ch = fgetc(fp); //�����ļ�����һ���ֽڶ���������ٴν����ж� 
	} 
	
	fclose(fp);
	
	return 0;
}
