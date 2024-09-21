#include <stdio.h>
#include <string.h>

void seedData(void) {
    FILE *studentFile = fopen("students.txt", "a+");
    FILE *teacherFile = fopen("teachers.txt", "a+");
    FILE *adminFile = fopen("administrators.txt", "a+");

    if (studentFile == NULL || teacherFile == NULL || adminFile == NULL) {
        printf("Error opening files for seeding.\n");
        return;
    }

    fseek(studentFile, 0, SEEK_END);
    fseek(teacherFile, 0, SEEK_END);
    fseek(adminFile, 0, SEEK_END);

    if (ftell(studentFile) == 0) {
        fprintf(studentFile, "2023001 张三 男 password123 1\n");
        fprintf(studentFile, "2023002 李四 女 password456 1\n");
        fprintf(studentFile, "2023003 王五 男 password789 1\n");
    }

    if (ftell(teacherFile) == 0) {
        fprintf(teacherFile, "T001 赵老师 女 teacherpass1 2\n");
        fprintf(teacherFile, "T002 钱老师 男 teacherpass2 2\n");
    }

    if (ftell(adminFile) == 0) {
        fprintf(adminFile, "A001 管理员 男 adminpass 3\n");
    }

    fclose(studentFile);
    fclose(teacherFile);
    fclose(adminFile);

    printf("Data seeding completed.\n");
}
