#include <stdio.h>
#include "mystring.h"


int main()
{
    char *str = "china";
    char buf[1024] = {0};

    reverseStr(str, buf);

    printf("%s\n", str);
    printf("%s\n", buf);

    return 0;
}

//int main1(int argc, char *argv[])
//{
//    //�����ǲ�����������Ƿ���, ��'\0֮ǰ���ַ�����'
//    char *str = "GREAT WALL";
//    printf("length = %d\n", myStrlen(str));

//    printf("%d\n", '0');

//    char buf[1024] = {0};
//    printf("%s\n", myStrcpy(buf, str));

//    char *str1 = " is in China";
//    printf("%s\n", myStrcat(buf, str1));

//    char name[] = "lianwence123456";
//    char name1[] = "lianwence";
//    if(myStrcmp(name, name1))
//    {
//        printf("�����!\n");
//    }
//    else
//    {
//        printf("���!\n");
//    }


//    char *p = "wen";
//    printf("%s\n", myStrstr(name, p));
//    return 0;
//}
