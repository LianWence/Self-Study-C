#include <stdio.h>
#include <stdlib.h>

typedef struct _struct_node
{
    //������
    int data;
    //ָ����
    struct _struct_node * next;
    struct _struct_node * pre;
} Dnode;

Dnode * createDoubleList()
{
    Dnode * head = (Dnode *)malloc(sizeof(Dnode));
    if(head == NULL)
    {
        printf("����˫������ʧ��!\n");
        exit(-1);
    }
    head->next = head;
    head->pre = head;
    return head;
}

void insertDoubleList(Dnode * head, int data)
{
    Dnode * cur = (Dnode *)malloc(sizeof(Dnode));
    if(NULL == cur)
    {
        printf("�����½ڵ�ʧ��!\n");
        exit(-1);
    }

    cur->data = data;
    //�������Ľڵ�����ָ��
    cur->next = head->next;
    cur->pre = head;
    head->next = cur;
    cur->next->pre = cur;
}

void traverseDoubleList(Dnode * head)
{
    Dnode *temp = head->next;
    while(temp != head)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int lengthDoubleList(Dnode * head)
{
    int length = 0;
    Dnode *temp = head->next;

    while(temp != head)
    {
        temp = temp->next;
        length++;
    }

    return length;
}

Dnode  * selectDoubleList(Dnode *head, int findData )
{
    Dnode *clock, *unclock;
    clock = head->next;
    unclock = head->pre;

    while(unclock != clock->pre)
    {
        if(clock->data == findData)
            return clock;
        if(unclock->data == findData)
            return unclock;
        if(clock == unclock)
            break;

        clock = clock->next;
        unclock = unclock->pre;
    }
    return NULL;
}

void deleteDoubleListNode(Dnode *node)
{
    node->pre->next = node->next;
    node->next->pre = node->pre;
    free(node);
}

void destroyDoubleList(Dnode *head)
{
    head->pre->next = NULL;
    Dnode *cur;

    while(head)
    {
        cur = head;
        head = head->next;
        free(cur);
    }
}

void sortDoubleList(Dnode *head)
{
    int length = lengthDoubleList(head);
    printf("����Ϊ%d\n", length);
    Dnode *p, *q;

    for(int i = 0; i < length - 1; i++)
    {
        p = head->next;
        q = head->next->next;
        for(int j = 0; j < length - 1 - i; j++)
        {
            if(p->data > q->data)
            {
                p->pre->next = q;
                q->pre = p->pre;
                p->next = q->next;
                p->pre = q;
                q->next = p;
                q->next->pre = p;

                q = p->next;
                continue;
            }

            p = p->next;
            q = p->next;
        }
    }
}

int main(int argc, char *argv[])
{
    Dnode * head = createDoubleList();

    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        insertDoubleList(head, rand() % 100);
    }

    traverseDoubleList(head);

    int len = lengthDoubleList(head);
    printf("length = %d\n", len);

    Dnode *node = selectDoubleList(head, 5);
    if(node)
    {
        printf("�ҵ���!\n");
        deleteDoubleListNode(node);
        printf("ɾ���ɹ�!\n");
        traverseDoubleList(head);
    }
    else
        printf("û���ҵ�!\n");

    sortDoubleList(head);
    printf("�������!\n");
    traverseDoubleList(head);

    destroyDoubleList(head);

    return 0;
}
