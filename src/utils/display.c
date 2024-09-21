#include "utils/display.h"
#include "models/student.h"
#include <stdarg.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

void clearScreen(void) {
    printf("\033[2J");
    printf("\033[H");
}

void printColored(const char *color, const char *format, ...) {
    va_list args;
    va_start(args, format);

    printf("%s", color);
    vprintf(format, args);
    printf("%s", RESET);

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

    int headerPadding = (terminalWidth - strlen(header)) / 2;
    int separatorPadding = (terminalWidth - strlen(separator)) / 2;

    printf("%*s", headerPadding, "");
    printColored(CYAN, "%s\n", header);
    printf("%*s", separatorPadding, "");
    printColored(CYAN, "%s\n", separator);

    while (data != NULL) {
        char row[100];
        printRow(data, row);
        int rowPadding = (terminalWidth - strlen(row)) / 2;
        printf("%*s", rowPadding, "");
        printColored(YELLOW, "%s\n", row);
        data = ((Student *) data)->next; // Assuming data is of type Student or Teacher
    }
}
