#include <stdio.h>
#include <stdlib.h>
#define fflush() while (getchar() != '\n')

#ifndef _WIN32
    #include <termios.h>
    #define system(command);
    char _getch(void)
    {
        struct termios oldSettings, newSettings;
        char ch;
        tcgetattr(0, &oldSettings);
        newSettings = oldSettings;
        newSettings.c_lflag &= ~ICANON;
        newSettings.c_lflag &= 0 ? ECHO : ~ECHO;
        tcsetattr(0, TCSANOW, &newSettings);
        ch = getchar();
        tcsetattr(0, TCSANOW, &oldSettings);
        return ch;
    }
#endif

void scanInt(int *elem)
{
    while (!scanf("%d", elem) || getchar() != '\n') {
        fflush();
        printf("Ожидалось целое число! Попробуйте снова: ");
    }
}


FILE *openFile(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("При открытии файла \"output.txt\" произошла ошибка!");
        system("pause");
        exit(-1);
    }
    return file;
}
