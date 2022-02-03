#include "lib/tools.h"
#include "lib/stack.h"


bool removeMinPosElem(STACK **head)
{
    STACK *current = *head, *minCurrent = current,
          *previous = NULL, *minPrevious = NULL;
    while (current = current -> next)
    {
        if (current -> value > 0)
            if (minCurrent -> value <= 0 || current -> value < minCurrent -> value)
            {
                minCurrent = current;
                minPrevious = previous;
            }
        previous = current;
    }
    if (minCurrent -> value > 0)
    {
        if (minPrevious)
            minPrevious -> next = minCurrent -> next;
        else
            *head = minCurrent -> next;
        free(minCurrent);
        return true;
    }
    return false;
}


int main(void)
{
    STACK *myStack;
    FILE *output = openFile("output.txt", "w");
    puts("Fill stack:");
    myStack = create();
    printf("\nOriginal stack: ");
    printToFile(myStack, stdout);
    if (removeMinPosElem(&myStack))
    {
        printf("After deleting minimal positive element: ");
        printToFile(myStack, stdout);
        printToFile(myStack, output);
    }
    else
        puts("There are no positive elements! Nothing to delete.");
    fclose(output);
    clear(myStack);
    system("pause");
    return 0;
}
