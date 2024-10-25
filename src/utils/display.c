#include "utils/display.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#endif

// Color constants for Windows
#ifdef _WIN32
#define RED "RED"
#define GREEN "GREEN"
#define YELLOW "YELLOW"
#define BLUE "BLUE"
#define MAGENTA "MAGENTA"
#define CYAN "CYAN"
#define RESET "RESET"
#endif

// Cross-platform function to get terminal width
int getTerminalWidth(void) {
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
    printf("\033[2J\033[H");
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
    int terminalWidth = getTerminalWidth();
    clearScreen();
    printf("\n");

    const char *border = "**************************************************************";
    int borderLength = strlen(border);
    int titleLength = strlen(title);
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

void centerPrint(const char *border, const char *format, ...) {
    va_list args;
    va_start(args, format);

    int terminalWidth = getTerminalWidth();
    int borderLength = strlen(border);
    int padding = (terminalWidth - borderLength) / 2;

    printf("%*s", padding, "");
    vprintf(format, args);

    va_end(args);
}

void printOption(int number, const char *text) {
    int terminalWidth = getTerminalWidth();
    const char *border = "**************************************************************";
    int borderLength = strlen(border);
    int padding = (terminalWidth - borderLength) / 2;
    printf("%*s", padding, "");
    printColored(GREEN, "%d. ", number);
    printf("%s\n", text);
}

void printPromptNoNewLine(const char *text) {
    int terminalWidth = getTerminalWidth();
    const char *border = "**************************************************************";
    int borderLength = strlen(border);
    int padding = (terminalWidth - borderLength) / 2;
    printf("%*s", padding, "");
    printColored(MAGENTA, text);
    printf(" ");
}


void centerColorPrint(const char *border, const char *color, const char *format, ...) {
    va_list args;
    va_start(args, format);

    int terminalWidth = getTerminalWidth();
    int borderLength = strlen(border);
    int padding = (terminalWidth - borderLength) / 2;

    printf("%*s", padding, "");
    setColor(color);
    vprintf(format, args);
    resetColor();

    va_end(args);
}

void printPrompt(const char *text) {
    printf("\n");
    printPromptNoNewLine(text);
}

void anyKey(void) {
    printPrompt("(Press any key to continue)");
    getchar();
}

void printTable(const char *header, const char *separator, void (*printRow)(void *, char *row), void *data) {
    int terminalWidth = getTerminalWidth();

    int headerPadding = (terminalWidth - strlen(header)) / 2;
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

void getInput(char *input, int maxLength) {
#ifdef _WIN32
    DWORD mode, originalMode;
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hInput, &originalMode);
    mode = originalMode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);
    SetConsoleMode(hInput, mode);
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif
    int i = 0;
    char c;

    while (1) {
        c = getchar();
        if (maxLength == 1) {
            printf("%c", c);
            input[0] = c;
            input[1] = '\0';
            break;
        }
        if (c == '\n' || c == '\r' || i == maxLength - 1) {
            input[i] = '\0';
            break;
        } else if (c == 127 || c == 8) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            input[i++] = c;
            printf("%c", c);
        }
    }
#ifdef _WIN32
    SetConsoleMode(hInput, originalMode);
    printf("\n");
#else
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    printf("\n");
#endif
}

void getPassword(char *password, int maxLength) {
#ifdef _WIN32
    DWORD mode, originalMode;
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hInput, &originalMode);
    mode = originalMode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);
    SetConsoleMode(hInput, mode);
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif
    int i = 0;
    char c;

    while (1) {
        c = getchar();
        if (c == '\n' || c == '\r' || i == maxLength - 1) {
            password[i] = '\0';
            break;
        } else if (c == 127 || c == 8) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            password[i++] = c;
            if (i == 1) {
                printf("*");
            } else {
                printf("\b*%c", c);
            }
        }
    }

#ifdef _WIN32
    SetConsoleMode(hInput, originalMode);
    printf("\n");
#else
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    printf("\n");
#endif
}
