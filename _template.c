#include "lib/tools.h"
#include "lib/stack.h"


// Target func.


int main(void)
{
    STACK *myStack;
    // Possibly another vars.
    FILE *output = openFile("output.txt", "w");
    puts("Fill stack:");
    myStack = create(); // Or fill(&myStack) if you need the stack length.
    // Possibly additional user input.
    printf("\nOriginal stack: ");
    printToFile(myStack, stdout);
    // Target func call + prints of results to stdout & output file.
    fclose(output);
    clear(myStack); // And for other used STACKs.
    system("pause");
    return 0;
}
