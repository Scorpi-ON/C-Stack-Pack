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
    setlocale(LC_ALL, "RUS");
    STACK *myStack;
    FILE *output = fopen("output.txt", "w");
    int num;

    puts("Заполните стек:");
    myStack = create();
    printf("\nИсходный список: ");
    printToFile(myStack, stdout);
    printf("\nВведите номер элемента, который хотите удалить: ");
    scanf("%d", &num);
    if (removeElemByNum(&myStack, num))
    {
        printf("\nИзменённый стек: ");
        printToFile(myStack, stdout);
        printToFile(myStack, output);
    }
    else
        puts("\nВ стеке нет элемента с таким номером! Нечего изменять.");

    fclose(output);
    clear(myStack);
    system("pause");
    return 0;
}
