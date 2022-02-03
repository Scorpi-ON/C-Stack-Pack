#include "lib/tools.h"
#include "lib/stack.h"


STACK *reverse(STACK *node)
{
    STACK *newNode = NULL;
    do
        push(&newNode, node -> value);
    while (node = node -> next);
    return newNode;
}


int main(void)
{
    STACK *myStack, *myReversedStack;
    FILE *output = fopen("output.txt", "w");
    if (output == NULL)
        perror("Error while opening \"output.txt\"");
    else
    {
        puts("Fill stack:");
        myStack = create();
        printf("\nOriginal stack: ");
        printToFile(myStack, stdout);
        printf("\nReversed stack: ");
        myReversedStack = reverse(myStack);
        printToFile(myReversedStack, stdout);
        clear(myStack);
        clear(myReversedStack);
    }
    system("pause");
    return 0;
}
