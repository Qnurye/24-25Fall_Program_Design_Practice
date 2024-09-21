#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>  
#include <string.h>  

#define MAX_ENTRIES 10  
#define ENTRY_SIZE 100  
char memo[MAX_ENTRIES][ENTRY_SIZE];
int numEntries = 0;

void addMemo(const char* text) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Memo is full!\n");
        return;
    }
    strncpy(memo[numEntries], text, ENTRY_SIZE - 1);
    memo[numEntries][ENTRY_SIZE - 1] = '\0';
    numEntries++;
    printf("Memo added successfully!\n");
}


void viewMemos() {
    if (numEntries == 0) {
        printf("Memo is empty!\n");
        return;
    }
    printf("Current memos:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d: %s\n", i + 1, memo[i]);
    }
}

void schedule_write()
{
    char input[ENTRY_SIZE];


    printf("Enter memo 1: ");
    fgets(input, ENTRY_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;
    addMemo(input);

    printf("Enter memo 2: ");
    fgets(input, ENTRY_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;
    addMemo(input);


    viewMemos();



   
}

