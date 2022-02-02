#include "libs/tools.h"
#include "libs/stack.h"


STACK *reverse(STACK *node)
{
    STACK *newNode = NULL;
    do
        push(&newNode, node -> value);
    while (node = node -> next);
    return newNode;
}


int main(void)
{
    setlocale(LC_ALL, "RUS");
    STACK *myStack, *myReversedStack;

    puts("Заполните стек:");
    myStack = create();
    printf("\nИсходный стек: ");
    display(myStack);
    printf("Перевёрнутый стек: ");
    myReversedStack = reverse(myStack);
    display(myReversedStack);

    clear(myStack);
    clear(myReversedStack);
    system("pause");
    return 0;
}
