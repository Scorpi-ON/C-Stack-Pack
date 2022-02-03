#include "lib/tools.h"
#include "lib/stack.h"


void removeElemByNum(STACK **head, int num)
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
    }
}


int main(void)
{
    STACK *myStack = NULL;
    int num, length;
    FILE *output = openFile("output.txt", "w");
    puts("Fill stack:");
    length = fill(&myStack);
    printf("\nOriginal stack: ");
    printToFile(myStack, stdout);
    printf("Enter the number of element you want to delete: ");
    scanInt(&num);
    while (num < 1 || num > length)
    {
        printf("Incorrect number! It should be from 1 "
               "to %d (stack length). Try again: ", length);
        scanInt(&num);
    }
    removeElemByNum(&myStack, num);
    printf("After deleting element № %d: ", num);
    printToFile(myStack, stdout);
    printToFile(myStack, output);
    fclose(output);
    clear(myStack);
    system("pause");
    return 0;
}
