#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include "models/grade.h"

#include "models/student.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void clearScreen(void);

void printColored(const char *color, const char *format, ...);

void printHeader(const char *title);

void printOption(int number, const char *text);

void printPrompt(const char *text);

void centerPrint(const char *border, const char *format, ...);

void centerColorPrint(const char *border, const char *color, const char *format, ...);

void printPromptNoNewLine(const char *text);

void anyKey(void);

void printTable(const char *header, const char *separator, void (*printRow)(void *, char *row), void *data);

void getInput(char *input, int maxLength);

void getPassword(char *password, int maxLength);

#endif
