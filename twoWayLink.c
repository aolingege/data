#include <stdio.h>
#include <stdlib.h>

typedef struct pn
{
    struct node *prev;
    struct node *next;
} pn;

typedef struct node
{
    int pos;
    int data;
    struct pn *pn;
} * lnode, *llist, node;

void insert(llist list, int data, int pos)
{
    if (!list)
    {
        list->pos = pos;
        list->data = data;
        list->pn = NULL;
    }
    else
    {
        // 申请一个临时的节点
        lnode tempNode = (lnode)malloc(sizeof(node));
        // 申请一个临时的指向指针
        pn *tempPn = (pn *)malloc(sizeof(pn));

        lnode tempList = list;
        // 移动到最后一个节点
        while (tempList->pn->next != NULL)
        {
            tempList = tempList->pn->next;
        }

        // 处理最后一个节点
        tempPn->prev = tempList;
        tempPn->next = NULL;

        // 处理倒数第二个节点
        tempList->pn->next = tempNode;

        // 数据赋值
        tempNode->pos = pos;
        tempNode->data = data;
        tempNode->pn = tempPn;
    }
}

void delete (llist list, int pos)
{
    if (list->pos == pos)
    {
        // 首先保存这个节点
        llist tempList = list;

        // 移到下个节点处理指向问题
        list = list->pn->next;
        list->pn->prev = NULL;

        // 释放节点空间
        free(tempList);
    }
    else
    {
        // 保证这个指向
        lnode tempList = list;
        // 下个节点指向
        lnode tempNode = tempList->pn->next;
        while (tempList->pn->next != NULL)
        {
            if (tempNode->pos == pos)
            {
                // 处理前面的一个节点
                tempList->pn->next = tempNode->pn->next;
                // 处理后面的一个节点
                tempNode->pn->next->pn->prev = tempList;
                free(tempNode);
                break;
            }
            else
            {
                // 没找到就向前移动一个节点
                tempList = tempNode;
                tempNode = tempNode->pn->next;
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
        lnode tempNode = list->pn->next;
        while (tempNode->pos != pos && tempNode->pn->next != NULL)
        {
            tempNode = tempNode->pn->next;
        }
        if (tempNode->pn->next != NULL)
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

void deleteList(llist list)
{
    lnode tempList = list;
    while (tempList->pn->next != NULL)
    {
        tempList = list;
        list = tempList->pn->next;
        free(tempList);
    }
    free(list);
}

void show(llist list)
{
    lnode tempNode = list;
    while (tempNode->pn->next != NULL)
    {
        printf("pos:%d,datat:%d\n", tempNode->pos, tempNode->data);
        tempNode = tempNode->pn->next;
    }
    printf("pos:%d,datat:%d\n", tempNode->pos, tempNode->data);
}

int main()
{
    llist list = (llist)malloc(sizeof(node));

    return 0;
}