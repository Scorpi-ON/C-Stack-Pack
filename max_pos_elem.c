#include "lib/tools.h"
#include "lib/stack.h"


bool removeMaxPosElem(STACK **head)
{
    STACK *current = *head,
          *previous = NULL,
          *maxCurrent = current,
          *maxPrevious = NULL;
    while (current = current -> next)
    {
        if (current -> value > 0)
            if (maxCurrent -> value <= 0 || current -> value > maxCurrent -> value)
            {
                maxCurrent = current;
                maxPrevious = previous;
            }
        previous = current;
    };
    if (maxCurrent -> value > 0)
    {
        if (maxPrevious)
            maxPrevious -> next = maxCurrent -> next;
        else
            *head = maxCurrent -> next;
        free(maxCurrent);
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
    if (removeMaxPosElem(&myStack))
    {
        printf("After deleting maximal positive element: ");
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
