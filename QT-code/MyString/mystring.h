#ifndef MYSTRING_H
#define MYSTRING_H

int myStrlen(const char *src);
char * myStrcpy(char *dst, const char *src);
char * myStrcat(char *dst, const char *src);
int myStrcmp(const char *str1, const char *str2);
char * myStrstr(char *str, char *subStr);
void trimLeftSpace(char *str);
void trimRightSpace(char *str);
void trimSpace(char *str);
void reverseStr(char *str, char *reverseStr);

#endif // MYSTRING_H
