#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _loginNode
{
    struct _loginNode *next;
    char *username;
    char *password;
} LoginNode;

void trverseList(LoginNode *head)
{
    head = head->next;
    while(head)
    {
        printf("%s:%s", head->username, head->password);
        head = head->next;
    }
}

void trimAllSpace(char *str)
{
    char *temp = str;
    while(*temp)
    {
        if(*temp != ' ')
        {
            *str++ = *temp;
        }

        temp++;
    }
}

int readConf(LoginNode **head, char *file)
{
    (*head) = (LoginNode *)malloc(sizeof(LoginNode));
    (*head)->next = NULL;

    FILE *pf = fopen(file, "r+");
    if(pf == NULL)
        exit(-1);

    LoginNode *cur = NULL;
    char buf[1024];
    while(fgets(buf, 1024, pf))
    {
        if(*buf == '#' || *buf == '[' || *buf == '\n')
            continue;

        trimAllSpace(buf);
        cur = (LoginNode *)malloc(sizeof (LoginNode));

        cur->next = (*head)->next;
        (*head)->next = cur;

        char *p = strtok(buf, "=\n");
        cur->username = (char *)malloc(strlen(p) + 1);
        strcpy(cur->username, p);

        p = strtok(NULL, "=\n");
        cur->password = (char *)malloc(strlen(p) + 1);
        strcpy(cur->password, p);
    }

    return 0;
}

int Login(LoginNode *head)
{
    trverseList(head);

    char username[1024] = {0};
    char password[1024] = {0};
    printf("username:");
    scanf("%s", username);
    printf("password:");
    scanf("%s", password);

    head = head->next;
    while(head)
    {
        if(strcmp(head->username, username) == 0 && strcmp(head->password, password) == 0)
            return 1;

        head = head->next;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    LoginNode *head;
    int result = readConf(&head, "passwd");
    if(result)
        exit(-1);

    int ret = Login(head);
    if(ret)
        printf("ÔÊÐíµÇÂ½!\n");
    else
        printf("²»ÔÊÐíµÇÂ½!\n");

    return 0;
}


