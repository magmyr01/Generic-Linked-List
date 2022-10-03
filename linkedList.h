#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H
#include "stdbool.h"
#include "node.h"

typedef struct LinkedList
{
    node *first;
    node *last;
    int count;
} LinkedList;

LinkedList *createList();
LinkedList *AddFirst(LinkedList *list, void *data);
LinkedList *AddLast(LinkedList *list, void *data);
LinkedList *RemoveFirst(LinkedList *list);
LinkedList *RemoveLast(LinkedList *list);
void PrintList(LinkedList *list, void (*print)(void *));

#endif /* __LINKEDLIST_H */