#include "lib/tools.h"
#include "lib/stack.h"


bool removeFirstEvenElem(STACK **head)
{
    STACK *current = *head,
          *previous = NULL;
    do
    {
        if (current -> value % 2 == 0)
        {
            if (previous)
                previous -> next = current -> next;
            else
                *head = current -> next;
            free(current);
            return true;
        }
        previous = current;
        current = current -> next;
    } while (current);
    return false;
}


int main(void)
{
    setlocale(LC_ALL, "RUS");
    STACK *myStack;
    FILE *output = fopen("output.txt", "w");

    puts("Заполните стек:");
    myStack = create();
    printf("Исходный список: ");
    printToFile(myStack, stdout);
    if (removeFirstEvenElem(&myStack))
    {
        printf("\nИзменённый стек: ");
        printToFile(myStack, stdout);
        printToFile(myStack, output);
    }
    else
        puts("\nВ стеке нет чётных чисел! Нечего изменять.");

    fclose(output);
    clear(myStack);
    system("pause");
    return 0;
}
