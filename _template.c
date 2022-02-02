#include "lib/tools.h"
#include "lib/stack.h"


// Your target func.


int main(void)
{
    setlocale(LC_ALL, "RUS");
    STACK *myStack; // And maybe another vars.

    puts("Заполните стек:");
    myStack = create(); // Or fill(&myStack) if you need the stack length.
    // Maybe additional user input.
    printf("\nИсходный стек: ");
    printToFile(myStack, stdout);
    // Target func call + prints of results to stdout or FILEs.

    clear(myStack); // And for other used STACKs.
    system("pause");
    return 0;
}
