#include <stdio.h>
#include "mystring.h"

int myStrlen(const char *src)
{
    int length = 0;
    while(*src++)
        length++;

    return length;
}

char * myStrcpy(char *dst, const char *src)
{
    char *temp = dst;

//    while(*src)
//    {
//        *temp++ = *src++;
//    }
//    *temp = '\0';
    //表达式是有返回值的,通常是指代赋值表达式的返回值

    while(*temp++ = *src++);//当表达式的返回值为'\0';循坏结束

    return dst;
}

char * myStrcat(char *dst, const char *src)
{
    char *temp = dst;

//    while(*temp++);
//    temp--;

    while(*temp)
        temp++;

    while(*temp++ = *src++);

    return dst;
}

int myStrcmp(const char *str1, const char *str2)
{
    for(; (*str1 && *str2) && (*str1 == *str2); str1++, str2++);
    return *str1 - *str2;
}

char * myStrstr(char *str, char *subStr)
{
    if(*subStr)
    {
        while(*str)
        {
            for(int n = 0; *(str + n) == *(subStr + n); n++)
            {
                if(*(subStr + n + 1) == '\0')
                    return str;
            }
            str++;
        }

        return NULL;
    }
    else
        return str;
}

void trimLeftSpace(char *str)
{
    while(*str)
        str++;

    while(*(--str) == ' ')
        *str = '\0';
}

void trimRightSpace(char *str)
{
    char *temp = str;
    while(*temp == ' ')
        temp++;

    while(*str++ = *temp++);
}

void trimSpace(char *str)
{
    char *temp = str;

    while(*temp)
    {
        if(*temp != ' ')
            *str++ = *temp;

        temp++;
    }

    *str = '\0';
}

void reverseStr(const char *str, char *revStr)
{
    if(!*str)
        *revStr =

    if(*str)
    {
        reverseStr(str + 1, revStr + 1);
        *revStr = *str;
    }
    else
        *++revStr = '\0';

}
