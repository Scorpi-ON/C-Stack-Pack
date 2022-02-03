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
    STACK *myStack;
    int elem;
    puts("Fill stack:");
    myStack = create();
    printf("\nOriginal stack: ");
    printToFile(myStack, stdout);
    printf("Enter the element you want to delete: ");
    scanInt(&elem);
    if (delFirstEntry(myStack, elem))
    {
        printf("After deleting the first entry of %d: ", elem);
        printToFile(myStack, stdout);
    }
    else
        printf("Element %d was not found! Nothing to delete.\n", elem);
    clear(myStack);
    system("pause");
    return 0;
}
