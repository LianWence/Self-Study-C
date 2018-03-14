#include <stdio.h>

int strlen(char *p);
char * strcat(char *p, char *q);
char * strcpy(char *des, char *src);
int * strcom(char *p, char *q); 
void handleArray(char **array);


int main(int argc, char** argv) {
	char array[100] = "china";
	printf("length = %d\n", strlen(array));
	puts("+++++++++++++++++++++++++++");
	
	char array1[] = " is my country";
	char array2[] = "! Good HAHAAHA"; 
	strcat(strcat(array, array1), array2);
	printf("%s\n", array);
	printf("length = %d\n", strlen(array));
	
	puts("+++++++++++++++++++++++++++");
	char copy1[3] = "ab";
	char copy2[10] = "www\0eeerrr";
	strcpy(copy1, copy2); 
	printf("%s\n", copy1);
	
	puts("+++++++++++++++++++++++++++");
	char *str1 = "chna";
	char *str2 = "chi";
	int result = strcmp(str1, str2);
	
	if(!result)
	{	
		printf("str1 == str2\n");
	}
	else if(result > 0)
	{
		printf("str1 > str2\n");
	} 
	else 
	{
		printf("str1 < str2\n");
	} 
	 
	 
	puts("+++++++++++++++++++++++++++"); 
	
	char * strArray[] = {"China", "England", "France", "Germeny"};
	int i = 0;
	for(; i < sizeof(strArray) / sizeof(*strArray); i++)
	{
		printf("%s\n", *(strArray + i));
	}
	puts("+++++++++++++排序后+++++++++"); 
	handleArray(strArray);
	for(; i < sizeof(strArray) / sizeof(*strArray); i++)
	{
		printf("%s\n", *(strArray + i));
	}
	
	
	
	char arr[] = "china";
	printf("%d\n", sizeof(arr));
	return 0;
}
/*
	计算字符串的长度,不包括'\0' 
*/
int strlen(char *p)
{
	int length = 0;
	while(*p++)
	{
		length++;
	}
	
	return length;
}

/*
	拼接字符串 
*/ 

char * strcat(char *des, char *src)
{
	char *temp = des;
	
	while(*des)
		des++;
	
	while(*des++ = *src++);
	
	return temp;	
} 

/*
	复制字符串 
*/

char * strcpy(char *des, char *src)
{
	char *temp = des;
	
	while(*des++ = *src++);
	
	return temp;
} 

/*
	字符串比较大小 
*/

int * strcom(char *p, char *q)
{
//	while(*p && *q)
//	{
//		if(*p != *q)
//		{
//			break;
//		}
//		p++;
//		q++;
//	}

	for(; *p && *q; p++, q++)
	{
		if(*p != *q)
		{
			break;
		}
	}
	
	return *p - *q;
	
} 

/*
	处理字符指针数组 
*/ 

void handleArray(char **array)
{
	//选择排序
	printf("%p\n", array);	
	int i = 0;
	for(; i < sizeof(array)/sizeof(*array) - 1; i++)
	{
		int index = i;
		int j = 0;
		for(j = i + 1; j < sizeof(array)/sizeof(*array); j++){
			int result = strcmp(array[i], array[j]);
			if(result > 0){
				index = j;
			}
		}
		if(index != i)
		{
			int temp = array[i];
			array[i] = array[index];
			array[index] = temp; 
		}
	} 
} 
