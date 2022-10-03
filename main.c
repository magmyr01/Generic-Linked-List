#include <stdio.h>
#include "linkedList.h"

void printNumb(void *numb);

int main(int args, char *argv[])
{
    LinkedList *lst = createList();

    // Test functions in empty list
    RemoveFirst(lst);
    // bool exist = Exists(lst, 2);

    // Add elements
    int number[] = {1, 2};
    AddFirst(lst, (void *)&number[0]);
    AddFirst(lst, (void *)&number[1]);

    // Test functions on list with items
    PrintList(lst, printNumb);
    RemoveFirst(lst);
    RemoveFirst(lst);
}

void printNumb(void *numb)
{
    int *num = (int *)numb;
    printf("%d", *num);
}