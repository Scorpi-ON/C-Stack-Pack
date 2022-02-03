#include "lib/tools.h"
#include "lib/stack.h"


bool swapFirstAndLast(STACK **head)
{
    STACK *current = *head,
          *previous = NULL;
    int headValue = (*head) -> value;
    while (current -> next)
        current = current -> next;
    if (headValue == current -> value)
        return false;
    (*head) -> value = current -> value;
    current -> value = headValue;
    return true;
}


int main(void)
{
    STACK *myStack;
    FILE *output = openFile("output.txt", "w");
    puts("Fill stack:");
    myStack = create();
    printf("\nOriginal stack: ");
    printToFile(myStack, stdout);
    if (swapFirstAndLast(&myStack))
    {
        printf("After swapping: ");
        printToFile(myStack, stdout);
        printToFile(myStack, output);
    }
    else
        puts("The first and the last elements are equal! Nothing to change.");
    fclose(output);
    clear(myStack);
    system("pause");
    return 0;
}
