#include <stdio.h>

// Declare test functions
void test_student(void);

void test_teacher(void);

void test_administrator(void);

int main(void) {
    printf("Running tests...\n");

    test_student();
    test_teacher();
    test_administrator();

    printf("All tests completed.\n");
    return 0;
}
