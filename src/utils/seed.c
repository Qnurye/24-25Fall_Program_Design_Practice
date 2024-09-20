#include <stdio.h>
#include <string.h>

void seedData() {
    FILE *studentFile = fopen("students.txt", "r");
    FILE *teacherFile = fopen("teachers.txt", "r");
    FILE *adminFile = fopen("administrators.txt", "r");

    if (studentFile == NULL || teacherFile == NULL || adminFile == NULL) {
        printf("Error opening files for seeding.\n");
        return;
    }

    fseek(studentFile, 0, SEEK_END);
    fseek(teacherFile, 0, SEEK_END);
    fseek(adminFile, 0, SEEK_END);

    if (ftell(studentFile) == 0) {
        fclose(studentFile);
        studentFile = fopen("students.txt", "w");
        fprintf(studentFile, "2023001 张三 男 1\n");
        fprintf(studentFile, "2023002 李四 女 1\n");
        fprintf(studentFile, "2023003 王五 男 1\n");
    }

    if (ftell(teacherFile) == 0) {
        fclose(teacherFile);
        teacherFile = fopen("teachers.txt", "w");
        fprintf(teacherFile, "T001 赵老师 女 2\n");
        fprintf(teacherFile, "T002 钱老师 男 2\n");
    }

    if (ftell(adminFile) == 0) {
        fclose(adminFile);
        adminFile = fopen("administrators.txt", "w");
        fprintf(adminFile, "A001 管理员 男 3\n");
    }

    fclose(studentFile);
    fclose(teacherFile);
    fclose(adminFile);

    printf("Data seeding completed.\n");
}
