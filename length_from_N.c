#include "lib/tools.h"
#include "lib/stack.h"


int main(void)
{
    STACK *myStack = NULL;
    int length, N;
    FILE *output = openFile("output.txt", "w");
    puts("Fill stack:");
    length = fill(&myStack);
    printf("\nOriginal stack: ");
    printToFile(myStack, stdout);
    printf("Enter N: ");
    scanInt(&N);
    while(N < 1 || N > length)
    {
        printf("Incorrect number! It should be from 1 "
               "to %d (stack length). Try again: ", length);
        scanInt(&N);
    }
    length -= N - 1;
    printf("Stack length starting from %d element: %d.\n", N, length);
    fprintf(output, "%d", length);
    fclose(output);
    clear(myStack);
    system("pause");
    return 0;
}
