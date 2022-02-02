#pragma(once)
#define STACK struct STACK

STACK
{
    int value;
    STACK *next;
};


STACK *create(void);
int fill(STACK **head);
void push(STACK **head, int value);
void clear(STACK *node);
void display(STACK *node);
