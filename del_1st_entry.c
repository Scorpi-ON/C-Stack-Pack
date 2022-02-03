#include "lib/tools.h"
#include "lib/stack.h"


bool delFirstEntry(STACK *node, int entry)
{
    if (node -> value == entry)
    {
        *node = *(node -> next);
        return true;
    }
    do if (node -> next && node -> next -> value == entry)
    {
        if (node -> next -> next)
            *(node -> next) = *(node -> next -> next);
        else
        {
            free(node -> next);
            node -> next = NULL;
        }
        return true;
    }
    while (node = node -> next);
    return false;
}


int main(void)
{
    int elem;
    STACK *myStack;

    puts("Fill stack:");
    myStack = create();
    printf("\nEnter the element you want to delete: ");
    scanInt(&elem);
    printf("\nOriginal stack: ");
    printToFile(myStack, stdout);
    if (delFirstEntry(myStack, elem))
    {
        printf("\nChanged stack: ");
        printToFile(myStack, stdout);
    }
    else
        printf("Element %d was not found! Nothing to delete.\n", elem);

    clear(myStack);
    system("pause");
    return 0;
}
