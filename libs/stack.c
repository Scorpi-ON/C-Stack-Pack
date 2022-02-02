#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#define STACK struct STACK
#define continueInput() puts("Продолжить (+ / другой символ)?") && _getch() == '+'

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
    int elem;
    for (int count = 1;
         count <= 2 || continueInput();
         count++)
    {
        printf("%d. ", count);
        scanInt(&elem);
        push(&myStack, elem);
    }
    return myStack;
}


int fill(STACK **head)
{
    int count, elem;
    for (count = 1;
         count <= 2 || continueInput();
         count++)
    {
        printf("%d. ", count);
        scanInt(&elem);
        push(head, elem);
    }
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


void display(STACK *node)
{
    printf("{ [%d", node -> value);
    while (node = node -> next)
        printf(", ->], [%d", node -> value);
    puts(", x] }");
}
