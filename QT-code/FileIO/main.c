#include <stdio.h>
#include <stdlib.h>

int  main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    FILE *pf = fopen("cc.txt", "w+");
    fwrite((void *)arr, 4, 10, pf);
    rewind(pf);

    int arrCpy[1024];
    int n = fread((void *) arrCpy, 8, 5, pf);
    printf("n = %d\n", n);
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", arrCpy[i]);
    }
    fclose(pf);
    return 0;
}

int main2()
{
    //fputs 处理字符流 并且是遇到\n就换行再写一行,遇到\0就读取结束
    //fgets 是处理字符流的 遇到\n就读取结束
    char arr[1024] = "a\nbc\0defg";
    FILE *pf = fopen("aa.txt", "w+");
    if(pf == NULL)
        exit(-1);
    fputs(arr, pf);
    char arrCpy[1024];
    rewind(pf);
    fgets(arrCpy, 1024, pf);
    printf("%s\n", arrCpy);
    fclose(pf);
    printf("\n+++++++++++++++\n");
    FILE *pfd = fopen("bb.txt", "wb+");
    fwrite((void *)arr, 1, 10, pfd);
    rewind(pfd);
    fread((void *)arrCpy, 1, 10, pfd);
    for(int i = 0; i < 10; i++)
    {
        printf("%x->%c\n", arrCpy[i], arrCpy[i]);
    }

    fclose(pfd);
    return 0;
}

int main1(int argc, char *argv[])
{
    FILE *pf = fopen("aa.txt", "wb+");
    if(pf == NULL)
        exit(-1);
    int arr[10] = {0, 1, 0xffffffff, 2, 3, 4, 5, 6, 7, 8};
//    fputs((char *)arr, pf);
//    fclose(pf);
//    printf("操作完成!\n");

    fwrite((void *)arr, 4, 10, pf);
    FILE *pfd = fopen("aa.txt", "rb");
    rewind(pf);
    int arrCpy[10];
    fread((void *)arrCpy, 4, 10, pfd);
    fclose(pf);
    fclose(pfd);
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", arrCpy[i]);
    }
    printf("%s\n", (char *)arrCpy);
    return 0;
}
