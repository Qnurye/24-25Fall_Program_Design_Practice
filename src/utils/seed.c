#include <stdio.h>
#include <string.h>

void seedData(void) {
    FILE *studentFile = fopen("students.txt", "a+");
    FILE *teacherFile = fopen("teachers.txt", "a+");
    FILE *gradeFile = fopen("grades.txt", "a+");
    FILE *notificationFile = fopen("notifications.txt", "a+");
    FILE *adminFile = fopen("administrators.txt", "a+");
    FILE *classroomFile = fopen("classrooms.txt", "a+");
    FILE *courseScheduleFile = fopen("course_schedules.txt", "a+");

    if (studentFile == NULL || teacherFile == NULL || adminFile == NULL || 
        classroomFile == NULL || courseScheduleFile == NULL || gradeFile == NULL || notificationFile == NULL) {
        printf("Error opening files for seeding.\n");
        return;
    }

    fseek(studentFile, 0, SEEK_END);
    fseek(teacherFile, 0, SEEK_END);
    fseek(adminFile, 0, SEEK_END);
    fseek(classroomFile, 0, SEEK_END);
    fseek(courseScheduleFile, 0, SEEK_END);
    fseek(gradeFile, 0, SEEK_END);
    fseek(notificationFile, 0, SEEK_END);

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

    if (ftell(classroomFile) == 0) {
        fprintf(classroomFile, "A101 50\n");
        fprintf(classroomFile, "B202 100\n");
        fprintf(classroomFile, "C303 80\n");
    }

    if (ftell(courseScheduleFile) == 0) {
        fprintf(courseScheduleFile, "1 CS101 1 0 1 2\n");
        fprintf(courseScheduleFile, "2 MATH201 2 1 3 5\n");
        fprintf(courseScheduleFile, "3 ENG301 3 2 6 7\n");
    }

    fclose(studentFile);
    fclose(teacherFile);
    fclose(adminFile);
    fclose(classroomFile);
    fclose(courseScheduleFile);
    fclose(gradeFile);
    fclose(notificationFile);

    printf("Data seeding completed.\n");
}
