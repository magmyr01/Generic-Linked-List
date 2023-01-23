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
void AddFirst(LinkedList *list, void *data);
void AddLast(LinkedList *list, void *data);
void RemoveFirst(LinkedList *list);
void RemoveLast(LinkedList *list);
void PrintList(LinkedList *list, void (*print)(void *));
void Union(LinkedList *list1, LinkedList *list2);
LinkedList *Sort(LinkedList *list, void (*cmp)(void *, void *));

#endif /* __LINKEDLIST_H */