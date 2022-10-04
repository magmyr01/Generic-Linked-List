#include <stdio.h>
#include "linkedList.h"

void printNumb(void *numb);

int main(int args, char *argv[])
{
    LinkedList *lst = createList();

    // Test functions in empty list
    RemoveFirst(lst);
    RemoveLast(lst);
    // PrintList(lst, printNumb);

    // Add elements
    int number[] = {1, 2};
    AddFirst(lst, (void *)&number[0]);
    AddFirst(lst, (void *)&number[1]);

    // Test functions on list with items
    // RemoveLast(lst);
    // RemoveFirst(lst);

    LinkedList *lst2 = createList();
    int numbers[] = {5, 2, 8};
    AddLast(lst2, (void *)&numbers[0]);
    AddLast(lst2, (void *)&numbers[1]);
    AddFirst(lst2, (void *)&numbers[2]);

    PrintList(lst2, printNumb);

    RemoveLast(lst2);

    printf("%s", "List 1: ");
    PrintList(lst, printNumb);
    printf("%s", "List 2: ");
    PrintList(lst2, printNumb);

    Union(lst, lst2);
    PrintList(lst, printNumb);
}

void printNumb(void *numb)
{
    int *num = (int *)numb;
    printf("%d", *num);
}