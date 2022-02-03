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
    FILE *output = openFile("output.txt", "w");
    puts("Fill stack:");
    myStack = create();
    printf("\nOriginal stack: ");
    printToFile(myStack, stdout);
    printf("Reversed stack: ");
    myReversedStack = reverse(myStack);
    printToFile(myReversedStack, stdout);
    printToFile(myReversedStack, output);
    fclose(output);
    clear(myStack);
    clear(myReversedStack);
    system("pause");
    return 0;
}
