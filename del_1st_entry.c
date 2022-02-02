#include "libs/tools.h"
#include "libs/stack.h"


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
    setlocale(LC_ALL, "RUS");
    int elem;
    STACK *myStack;

    puts("Заполните стек:");
    myStack = create();
    printf("\nВведите элемент, который нужно удалить: ");
    scanInt(&elem);
    printf("\nИсходный стек: ");
    printToFile(myStack, stdout);
    if (delFirstEntry(myStack, elem))
    {
        printf("После удаления первого вхождения %d: ", elem);
        printToFile(myStack, stdout);
    }
    else
        printf("Элемент %d не найден! Нечего удалять.\n", elem);

    clear(myStack);
    system("pause");
    return 0;
}
