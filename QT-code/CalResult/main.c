#include <stdio.h>

void func(int a)
{
    printf("a = %d\n", a);

    return;
}

int main(int argc, char *argv[])
{
    char *c[] = {"INTER", "NEW", "POINTER", "FIRST"};
    char **cp[] = {c+3, c+2, c+1, c};
    char ***cpp= cp;

//    char **cc = c;
//    printf("%s\n", *cc+3);
    //cpp的值也在改变
    printf("%s\n", **++cpp);    //POINTER
    printf("%s\n", *--*++cpp+3); //ER
    printf("%s\n", *cpp[-2]+3);   //ST
    printf("%s\n", cpp[-1][-1]+1); //EW

//    printf("%s\n", c[1]);

    printf("%p\n", func);

    ((void (*) (int ) ) 0x000000013F3B11A9)(2);

//    void (*p) (int a) = func;
//    p(1);
    return 0;
}
