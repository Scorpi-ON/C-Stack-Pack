#pragma(once)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define fflush() while (getchar() != '\n')

#ifndef _WIN32
    #define system(command);
    char _getch(void);
#endif

void scanInt(int *elem);
