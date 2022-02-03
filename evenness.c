#include "lib/tools.h"
#include "lib/stack.h"


int getStackParity(STACK **head)
{
    bool even = false,
         odd = false;
    STACK *current = *head;
    do
    {
        if (current -> value % 2 == 0)
            even = true;
        else
            odd = true;
        current = current -> next;
    } while (current);
    if (even && odd)
        return 2;
    if (odd)
        return 1;
    return 0;
}


int main(void)
{
    STACK *myStack;
    FILE *output = openFile("output.txt", "w");
    puts("Fill stack:");
    myStack = create();
    printf("\nOriginal stack: ");
    printToFile(myStack, stdout);
    printToFile(myStack, output);
    switch (getStackParity(&myStack))
    {
        case 0:
            puts("The stack is even.");
            break;
        case 1:
            puts("The stack is odd.");
            break;
        default:
            puts("The stack is neither even nor odd.");
    }
    fclose(output);
    clear(myStack);
    system("pause");
    return 0;
}
