#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#define STACK struct STACK
#define continueInput() puts("Continue (+ / other symbol)?") && _getch() == '+'

STACK
{
    int value;
    STACK *next;
};


void push(STACK **head, int value)
{
    STACK *newNode = malloc(sizeof(STACK));
    newNode -> value = value;
    newNode -> next = *head;
    *head = newNode;
}


STACK *create(void)
{
    STACK *myStack = NULL;
    int count = 0,
        elem;
    do
    {
        printf("%d. ", ++count);
        scanInt(&elem);
        push(&myStack, elem);
    }
    while (count < 2 || continueInput());
    return myStack;
}


int fill(STACK **head)
{
    int count = 0,
        elem;
    do
    {
        printf("%d. ", ++count);
        scanInt(&elem);
        push(head, elem);
    }
    while (count < 2 || continueInput());
    return count;
}


void clear(STACK *node)
{
    STACK *next;
    do
    {
        next = node -> next;
        free(node);
    }
    while (node = next);
}


void printToFile(STACK *node, FILE *output)
{
    fprintf(output, "{ [%d", node -> value);
    while (node = node -> next)
        fprintf(output, ", ->], [%d", node -> value);
    fprintf(output, ", x] }\n");
}
