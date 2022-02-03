#include "lib/tools.h"
#include "lib/stack.h"


int getFrequency(STACK *head, int elem)
{
    STACK *current = head;
    int frequency = 0;
    do
    {
        if (current -> value == elem)
            frequency++;
    } while (current = current -> next);
    return frequency;
}


void printFrequenciesIntoFile(STACK *head, FILE *output)
{
    STACK *current = head;
    int currentNum = 0,
        *usedElems = NULL;
    bool isUnique;
    do
    {
        isUnique = true;
        for (int i = 0; i < currentNum; i++)
            if (current -> value == usedElems[i])
                isUnique = false;
        if (isUnique)
        {
            fprintf(output, "%d: %d\n", current -> value, getFrequency(head, current -> value));
            usedElems = realloc(usedElems, (currentNum + 1) * sizeof(int));
            usedElems[currentNum++] = current -> value;
        }
    } while (current = current -> next);
}


int main(void)
{
    STACK *myStack;
    FILE *output = fopen("output.txt", "w+");

    puts("Fill stack:");
    myStack = create();
    printf("\nOriginal stack: ");
    printToFile(myStack, stdout);
    printFrequenciesIntoFile(myStack, output);

    fclose(output);
    clear(myStack);
    system("pause");
    return 0;
}
