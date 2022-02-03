#include "lib/tools.h"
#include "lib/stack.h"


bool removeElemByNum(STACK **head, int num)
{
    STACK *current = *head,
          *previous = NULL;
    int i = 1;
    for (; i < num && current; i++)
    {
        previous = current;
        current = current -> next;
    }
    if (i == num)
    {
        if (previous)
            previous -> next = current -> next;
        else
            *head = current -> next;
        free(current);
        return true;
    }
    return false;
}


int main(void)
{
    STACK *myStack;
    int num;
    FILE *output = openFile("output.txt", "w");
    puts("Fill stack:");
    myStack = create();
    printf("\nOriginal stack: ");
    printToFile(myStack, stdout);
    printf("\nEnter the number of element you want to delete: ");
    scanInt(&num);
    if (removeElemByNum(&myStack, num))
    {
        printf("\nChanged stack: ");
        printToFile(myStack, stdout);
        printToFile(myStack, output);
    }
    else
        puts("\nThe number you entered is greater than the stack length! Nothing to change.");
    fclose(output);
    clear(myStack);
    system("pause");
    return 0;
}
