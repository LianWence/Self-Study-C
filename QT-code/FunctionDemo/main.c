#include <stdio.h>
#include <stdlib.h>

//FILE * stdin/stdout;

int main(int argc, char *argv[])
{
    int a = 10000;

    FILE *pf = fopen("aa.txt", "w+");
    printf("%d", a);
    fprintf(pf, "%d\n", a);
    fprintf(stdout, "%d\n", a);
    fclose(pf);

    char ip[16];
    int ip1, ip2, ip3, ip4;
    scanf("%d%d%d%d", &ip1, &ip2, &ip3, &ip4);
    sprintf(ip, "%d.%d.%d.%d", ip1, ip2, ip3, ip4);
    printf("%s\n", ip);

    return 0;
}
