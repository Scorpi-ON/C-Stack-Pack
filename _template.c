#include "lib/tools.h"
#include "lib/stack.h"


// Целевая функция


int main(void)
{
    #ifdef _WIN32
    system("chcp 1251");
    #endif
    STACK *myStack;
    // Возможно, какие-то переменные
    FILE *output = openFile("output.txt", "w");
    puts("Fill stack:");
    myStack = create(); // Можно вызвать fill(&myStack), если нужно получить длину стека
    printf("\nOriginal stack: ");
    printToFile(myStack, stdout);
    /* Возможно, дополнительный пользовательский ввод, вызов целевой функции,
       а также печать результатов в stdout и выходные файлы */
    fclose(output);
    clear(myStack); // Нужно вызвать и для других стеков, созданных в программе
    system("pause");
    return 0;
}
