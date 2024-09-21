#include "controllers/grade_controller.h"
#include "models/grade.h"
#include "models/student.h"
#include "utils/display.h"
#include "views/student_view.h"

void displayStudentGrades(const char *student_id, Grade *gradesHead) {
    Grade *studentGrades = getAllGradesByStudentID(gradesHead, student_id);
    displayGrades(studentGrades);
    freeGrades(&studentGrades);
}

void processUploadGrade(Student *studentsHead, Grade **gradesHead,
                        const char *student_id, const char *course_name,
                        int usual_grade, int final_grade, float usual_grade_proportion) {
    Student *student = findStudentByID(studentsHead, student_id);
    if (student == NULL) {
        printColored(RED, "学生不存在。\n");
        return;
    }

    addGrade(gradesHead, student_id, course_name, usual_grade, final_grade, usual_grade_proportion);
    printColored(GREEN, "成绩已成功上传。\n");
}
