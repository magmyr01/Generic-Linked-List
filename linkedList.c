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

void AddFirst(LinkedList *list, void *data)
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
}

void AddLast(LinkedList *list, void *data)
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

void RemoveFirst(LinkedList *list)
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
}

void RemoveLast(LinkedList *list)
{
    if (list->count == 0)
        return;
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
        list->count--;
        free(tmp);
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

void Union(LinkedList *list1, LinkedList *list2)
{
    if (list1->count == 0)
        return;
    if (list2->count == 0)
        return;
    list1->last->next = list2->first;
    list2->first->prev = list1->last;
    list1->count += list2->count;
}

void Swap(node *item1, node *item2)
{
    if (item2->next != NULL && item1->prev != NULL)
    {
        item1->next = item2->next;
        item2->next->prev = item1;
        item1->prev->next = item2;
        item2->prev = item1->prev;
        item2->next = item1;
        item1->prev = item2;
    }
}

LinkedList *Sort(LinkedList *list, int (*cmp)(void *, void *))
{
    node **arrayOfList = malloc(list->count);
    node *tmp = list->first;
    int i = 0;

    while (tmp != NULL)
    {
        arrayOfList[i] = tmp;
        tmp = tmp->next;
        i++;
    }
    int u = 9;
}