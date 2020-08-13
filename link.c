#include <stdio.h>

typedef struct node
{
    int pos;
    int data;
    struct node *next;
} *llist, *lnode, node;

void insert(llist list, int data, int pos)
{
    if (!list)
    {
        list->pos = pos;
        list->data = data;
        list->next = NULL;
    }
    else
    {
        lnode tempNode = (lnode)malloc(sizeof(node));
        tempNode->pos = pos;
        tempNode->data = data;
        tempNode->next = NULL;

        llist tempList = list;
        while (tempList->next != NULL)
        {
            tempList = tempList->next;
        }
        tempList->next = tempNode;
    }
}

void delete (llist list, int pos)
{
    if (list->pos == pos)
    {
    }
}