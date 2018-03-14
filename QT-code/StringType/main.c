#include <stdio.h>

int main(int argc, char *argv[])
{

    printf("%s\n", "china");
    printf("%c\n", * "china");
    printf("%c\n", "china"[3]);
    printf("%p\n", "china");

    char buf[] = "china";
    printf("sizeof(buf) = %d\n", (int)sizeof(buf));
    printf("sizeof(\"china\") = %d\n", (int)sizeof("china"));

    printf("buf = %p\n", buf);
    printf("(buf + 1) = %p\n", buf + 1);

    char arr[5] = "china is my country";
    printf("数组界限溢出%s\n", arr);
    return 0;
}
