#include "utils/display.h"
#include "models/student.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

// Cross-platform function to get terminal width
int getTerminalWidth() {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
#else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
#endif
}

// Cross-platform function to set text color
void setColor(const char *color) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD colorAttribute;
    if (strcmp(color, RED) == 0) colorAttribute = FOREGROUND_RED;
    else if (strcmp(color, GREEN) == 0) colorAttribute = FOREGROUND_GREEN;
    else if (strcmp(color, YELLOW) == 0) colorAttribute = FOREGROUND_RED | FOREGROUND_GREEN;
    else if (strcmp(color, BLUE) == 0) colorAttribute = FOREGROUND_BLUE;
    else if (strcmp(color, MAGENTA) == 0) colorAttribute = FOREGROUND_RED | FOREGROUND_BLUE;
    else if (strcmp(color, CYAN) == 0) colorAttribute = FOREGROUND_GREEN | FOREGROUND_BLUE;
    else colorAttribute = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    SetConsoleTextAttribute(hConsole, colorAttribute);
#else
    printf("%s", color);
#endif
}

// Cross-platform function to reset text color
void resetColor() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
    printf("%s", RESET);
#endif
}

void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J");
    printf("\033[H");
#endif
}

void printColored(const char *color, const char *format, ...) {
    va_list args;
    va_start(args, format);

    setColor(color);
    vprintf(format, args);
    resetColor();

    va_end(args);
}

void printHeader(const char *title) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int terminalWidth = w.ws_col;

    clearScreen();
    printf("\n");

    const char *border = "********************************************";
    int borderLength = strlen(border);
    int titleLength = strlen(title) / 3 * 2;
    int padding = (terminalWidth - borderLength) / 2;
    int titlePadding = (borderLength - titleLength - 6) / 2;

    printf("%*s", padding, "");
    printColored(CYAN, "%s\n", border);

    printf("%*s", padding, "");
    printColored(CYAN, "***");
    printf("%*s", titlePadding, "");
    printColored(YELLOW, "%s", title);
    printf("%*s", titlePadding, "");
    printColored(CYAN, "***\n");

    printf("%*s", padding, "");
    printColored(CYAN, "%s\n", border);
    printf("\n");
}

void printOption(int number, const char *text) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int terminalWidth = w.ws_col;
    const char *border = "********************************************";
    int borderLength = strlen(border);
    int padding = (terminalWidth - borderLength) / 2;
    printf("%*s", padding, "");
    printColored(GREEN, "%d. ", number);
    printf("%s\n", text);
}

void printPromptNoNewLine(const char *text) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int terminalWidth = w.ws_col;
    const char *border = "********************************************";
    int borderLength = strlen(border);
    int padding = (terminalWidth - borderLength) / 2;
    printf("%*s", padding, "");
    printColored(MAGENTA, text);
    printf(" ");
}

void printPrompt(const char *text) {
    printf("\n");
    printPromptNoNewLine(text);
}

void anyKey(void) {
    printPrompt("（按任意键继续）");
    getchar(); // Consume the newline character left by the previous input
    getchar(); // Wait for the user to press any key
}

void printTable(const char *header, const char *separator, void (*printRow)(void *, char *row), void *data) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int terminalWidth = w.ws_col;

    int headerPadding = (terminalWidth - strlen(header) / 3 * 2) / 2;
    int separatorPadding = (terminalWidth - 44) / 2;

    printf("%*s", headerPadding, "");
    printColored(CYAN, "%s\n", header);
    printf("%*s", separatorPadding, "");
    printColored(CYAN, "%s\n", separator);

    while (data != NULL) {
        char row[100];
        printRow(data, row);
        printf("%*s", headerPadding, "");
        printColored(YELLOW, "%s\n", row);
        data = ((Student *) data)->next; // Assuming data is of type Student or Teacher
    }
}
