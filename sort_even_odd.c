#include "lib/tools.h"
#include "lib/stack.h"


void sort(STACK **original, STACK **even, STACK **odd)
{
    STACK *current = *original;
    do
    {
        if (current -> value % 2 == 0)
            push(even, current -> value);
        else
            push(odd, current -> value);
        current = current -> next;
    }
    while (current);
}


int main(void)
{
    STACK *myStack,
          *even = NULL,
          *odd = NULL;
    FILE *output = openFile("output.txt", "w");
    puts("Fill stack:");
    myStack = create();
    printf("\nOriginal stack: ");
    printToFile(myStack, stdout);
    sort(&myStack, &even, &odd);
    if (even)
    {
        printf("List of even numbers: ");
        printToFile(even, stdout);
        printToFile(even, output);
    }
    if (odd)
    {
        printf("List of odd numbers: ");
        printToFile(odd, stdout);
        printToFile(odd, output);
    }
    fclose(output);
    clear(myStack);
    clear(even);
    clear(odd);
    system("pause");
    return 0;
}
