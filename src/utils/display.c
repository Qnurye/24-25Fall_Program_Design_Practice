#include "utils/display.h"
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
    printf("    ");
    printColored(GREEN, "%d. ", number);
    printf("%s\n", text);
}


void printPromptNoNewLine(const char *text) {
    printColored(MAGENTA, text);
    printf(" ");
}

void printPrompt(const char *text) {
    printf("\n");
    printPromptNoNewLine(text);
}
