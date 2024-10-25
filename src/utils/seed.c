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
        fprintf(studentFile, "2023004 Alice Female password321 1\n");
        fprintf(studentFile, "2023005 Bob Male password654 1\n");
        fprintf(studentFile, "2023006 Carol Female password987 1\n");
    }

    if (ftell(teacherFile) == 0) {
        fprintf(teacherFile, "T001 David Female teacherpass1 2\n");
        fprintf(teacherFile, "T002 Josh Male teacherpass2 2\n");
        fprintf(teacherFile, "T003 Sarah Female teacherpass3 2\n");
        fprintf(teacherFile, "T004 Linda Female teacherpass4 2\n");
    }

    if (ftell(adminFile) == 0) {
        fprintf(adminFile, "A001 Admin Male adminpass 3\n");
        fprintf(adminFile, "A002 SuperAdmin Female superadminpass 3\n");
    }

    if (ftell(classroomFile) == 0) {
        fprintf(classroomFile, "A101 50\n");
        fprintf(classroomFile, "B202 100\n");
        fprintf(classroomFile, "C303 80\n");
        fprintf(classroomFile, "D404 40\n");
        fprintf(classroomFile, "E505 60\n");
    }
    if (ftell(courseScheduleFile) == 0) {
        fprintf(courseScheduleFile, "1 Discrete_Mathematics 1 0 1 2 T001\n");
        fprintf(courseScheduleFile, "2 Data_Structures 2 1 3 5 T002\n");
        fprintf(courseScheduleFile, "3 Advanced_Mathematics 3 2 6 7 T001\n");
        fprintf(courseScheduleFile, "4 Algorithms 4 3 4 5 T003\n");
        fprintf(courseScheduleFile, "5 Computer_Networks 1 4 1 2 T004\n");
        fprintf(courseScheduleFile, "6 Operating_Systems 2 0 3 4 T002\n");
        fprintf(courseScheduleFile, "7 Software_Engineering 3 5 2 4 T003\n");
        fprintf(courseScheduleFile, "8 Database_Systems 2 6 1 3 T004\n");
        fprintf(courseScheduleFile, "9 Artificial_Intelligence 3 0 4 6 T002\n");
        fprintf(courseScheduleFile, "10 Machine_Learning 4 2 3 5 T001\n");
        fprintf(courseScheduleFile, "11 Cyber_Security 1 3 2 3 T003\n");
        fprintf(courseScheduleFile, "12 Cloud_Computing 2 4 4 5 T004\n");
        fprintf(courseScheduleFile, "13 Mobile_Development 3 1 5 6 T002\n");
        fprintf(courseScheduleFile, "14 Web_Technologies 4 2 1 2 T001\n");
        fprintf(courseScheduleFile, "15 Game_Development 1 5 3 6 T003\n");
        fprintf(courseScheduleFile, "16 Computer_Graphics 2 6 4 5 T004\n");
        fprintf(courseScheduleFile, "17 Human_Computer_Interaction 3 0 1 2 T002\n");
        fprintf(courseScheduleFile, "18 Robotics 4 2 3 4 T001\n");
        fprintf(courseScheduleFile, "19 Quantum_Computing 1 4 5 6 T003\n");
        fprintf(courseScheduleFile, "20 Big_Data 2 1 2 3 T004\n");
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
