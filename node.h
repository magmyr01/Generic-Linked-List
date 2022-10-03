#ifndef __NODE_H
#define __NODE_H

typedef struct Node
{
    void *obj;
    struct Node *next;
    struct Node *prev;
} node;

node *createNode(void *data);

#endif /* __NODE_H */