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
        fprintf(studentFile, "2023001 Tom Male password123 1\n");
        fprintf(studentFile, "2023002 Jerry Female password456 1\n");
        fprintf(studentFile, "2023003 John Male password789 1\n");
    }

    if (ftell(teacherFile) == 0) {
        fprintf(teacherFile, "T001 David Female teacherpass1 2\n");
        fprintf(teacherFile, "T002 Josh Male teacherpass2 2\n");
    }

    if (ftell(adminFile) == 0) {
        fprintf(adminFile, "A001 Admin Male adminpass 3\n");
    }

    if (ftell(classroomFile) == 0) {
        fprintf(classroomFile, "A101 50\n");
        fprintf(classroomFile, "B202 100\n");
        fprintf(classroomFile, "C303 80\n");
    }

    if (ftell(courseScheduleFile) == 0) {
        fprintf(courseScheduleFile, "1 Discrete_Mathematics 1 0 1 2 T001\n");
        fprintf(courseScheduleFile, "2 Data_Structures 2 1 3 5 T002\n");
        fprintf(courseScheduleFile, "3 Advanced_Mathematics 3 2 6 7 T001\n");
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
