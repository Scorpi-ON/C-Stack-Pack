#include "lib/tools.h"
#include "lib/stack.h"


bool removeFirstMultipleOfThree(STACK **head)
{
    STACK *current = *head,
          *previous = NULL;
    do
    {
        if (current -> value % 3 == 0)
        {
            if (previous)
                previous -> next = current -> next;
            else
                *head = current -> next;
            free(current);
            return true;
        }
        previous = current;
        current = current -> next;
    } while (current);
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
    if (removeFirstMultipleOfThree(&myStack))
    {
        printf("After deleting the first number multiple of 3: ");
        printToFile(myStack, stdout);
        printToFile(myStack, output);
    }
    else
        puts("There are no numbers multiple of 3! Nothing to delete.");
    fclose(output);
    clear(myStack);
    system("pause");
    return 0;
}
