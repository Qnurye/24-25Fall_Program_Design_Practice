#include <stdio.h>

// Declare test functions
void test_student();
void test_teacher();
void test_administrator();

int main() {
    printf("Running tests...\n");

    test_student();
    test_teacher();
    test_administrator();

    printf("All tests completed.\n");
    return 0;
}
