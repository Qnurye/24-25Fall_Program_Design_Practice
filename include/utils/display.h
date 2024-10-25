#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include "models/grade.h"

#include "models/student.h"
// ANSI color codes (for Unix-like systems)
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Cross-platform screen utilities
void clearScreen(void);

// Cross-platform colored text printing
void printColored(const char *color, const char *format, ...);

// Prints a centered header with a border
void printHeader(const char *title);

// Prints a numbered option in colored text
void printOption(int number, const char *text);

// Prints a centered prompt without a newline
void printPromptNoNewLine(const char *text);

// Prints a centered prompt with a newline
void printPrompt(const char *text);

// Waits for any key input to continue
void anyKey(void);

// Prints text in the center with specified border
void centerPrint(const char *border, const char *format, ...);

// Prints centered, colored text with a specified border
void centerColorPrint(const char *border, const char *color, const char *format, ...);

void printPromptNoNewLine(const char *text);

void anyKey(void);

void printTable(const char *header, const char *separator, void (*printRow)(void *, char *row), void *data);

// Receives user input with a specified maximum length
void getInput(char *input, int maxLength);

// Receives user input as a hidden password with a specified maximum length
void getPassword(char *password, int maxLength);

#endif // DISPLAY_H
