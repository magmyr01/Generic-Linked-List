#include "node.h"
#include <stdlib.h>
#include <stdio.h>

node *createNode(void *data)
{
    node *newN = (node *)malloc(sizeof(node));
    newN->next = NULL;
    newN->prev = NULL;
    newN->obj = data;

    return newN;
}