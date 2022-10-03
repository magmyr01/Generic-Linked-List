#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *createList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->count = 0;
    list->first = NULL;
    list->last = NULL;

    return list;
}

LinkedList *AddFirst(LinkedList *list, void *data)
{
    node *newNode = createNode(data);

    if (list->count == 0)
    {
        list->first = newNode;
        list->last = newNode;
    }
    else
    {
        node *tmp = list->first;
        list->first = newNode;
        newNode->next = tmp;
        tmp->prev = list->first;
    }

    list->count++;
    return list;
}

LinkedList *AddLast(LinkedList *list, void *data)
{
    node *newN = createNode(data);

    if (list->count == 0)
    {
        list->first = newN;
        list->last = newN;
    }
    else
    {
        list->last->next = newN;
        newN->prev = list->last;
        list->last = newN;
    }
    list->count++;
}

LinkedList *RemoveFirst(LinkedList *list)
{
    if (list->count == 1)
    {
        node *tmp = list->first;
        list->first = NULL;
        list->last = NULL;
        free(tmp);
        list->count--;
    }
    else if (list->count > 1)
    {
        node *tmp = list->first;
        list->first = tmp->next;
        list->first->prev = NULL;
        free(tmp);
        list->count--;
    }
    return list;
}

LinkedList *RemoveLast(LinkedList *list)
{
    if (list->count == 0)
        return list;
    else if (list->count == 1)
    {
        node *tmp = list->first;
        list->first = NULL;
        list->last = NULL;
        list->count--;
        free(tmp);
    }
    else
    {
        node *tmp = list->last;
        list->last = list->last->prev;
        list->last->next = NULL;
    }
}

void PrintList(LinkedList *list, void (*print)(void *))
{
    node *ptr = list->first;
    while (ptr != NULL)
    {
        print(ptr->obj);
        printf(" ");
        ptr = ptr->next;
    }
    putchar('\n');
}