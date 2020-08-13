#include <stdio.h>

typedef struct node
{
    int pos;
    int data;
    struct node *next;
} * llist, *lnode, node;

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
    // 如果找到该节点
    if (list->pos == pos)
    {
        // 链表指针临时存储
        llist tempNode = list;
        // 链表移到下个节点
        list = list->next;
        // 释放空间
        free(tempNode);
    }
    else
    {
        // 1. 移到下一个，这里tempList比currentNode慢一个节点
        lnode tempList = list;
        lnode currentNode = tempList->next;

        // 2. 开始遍历
        while (tempList->next != NULL)
        {
            if (currentNode->pos = pos)
            {
                tempList->next = currentNode->next;
                free(currentNode);
                break;
            }
            else
            {
                // 向前移一个节点
                tempList = currentNode;
                currentNode = currentNode->next;
            }
        }
    }
}

void setData(llist list, int data, int pos)
{
    if (list->pos == pos)
    {
        list->data = data;
    }
    else
    {
        lnode tempNode = list->next;
        while (tempNode->pos != pos && tempNode->next != NULL)
        {
            tempNode = tempNode->next;
        }
        if (tempNode->next != NULL)
        {
            tempNode->data = data;
        }
        else if (tempNode->pos == pos)
        {
            tempNode->data = data;
        }
        else
        {
            printf("未找到该节点");
        }
    }
}