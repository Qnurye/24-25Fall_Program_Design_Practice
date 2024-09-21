#include <stdio.h>
#include <string.h>
#include "../src/models/grade.c"

// 测试添加成绩功能
void test_addGrade(void) {
    Grade *head = NULL;
    addGrade(&head, "2023001", "数学", 80, 90, 0.4f);

    if (head != NULL &&
        strcmp(head->student_id, "2023001") == 0 &&
        strcmp(head->course_name, "数学") == 0 &&
        head->usual_grade == 80 &&
        head->final_grade == 90 &&
        head->usual_grade_proportion == 0.4f) {
        printf("test_addGrade passed\n");
    } else {
        printf("test_addGrade failed\n");
    }

    freeGrades(&head);
}

// 测试从文件加载成绩
void test_loadGradesFromFile(void) {
    FILE *file = fopen("test_grades.txt", "w");
    fprintf(file, "2023001 数学 80 90 0.4\n");
    fclose(file);

    Grade *head = loadGradesFromFile("test_grades.txt");

    if (head != NULL &&
        strcmp(head->student_id, "2023001") == 0 &&
        strcmp(head->course_name, "数学") == 0 &&
        head->usual_grade == 80 &&
        head->final_grade == 90 &&
        head->usual_grade_proportion == 0.4f) {
        printf("test_loadGradesFromFile passed\n");
    } else {
        printf("test_loadGradesFromFile failed\n");
    }

    freeGrades(&head);
    remove("test_grades.txt");
}

// 测试根据学生ID查找成绩
void test_findGradeByStudentID(void) {
    Grade *head = NULL;
    addGrade(&head, "2023001", "数学", 80, 90, 0.4f);
    addGrade(&head, "2023002", "英语", 85, 95, 0.5f);

    Grade *found = findGradeByStudentID(head, "2023001");
    if (found != NULL &&
        strcmp(found->course_name, "数学") == 0 &&
        found->usual_grade == 80 &&
        found->final_grade == 90 &&
        found->usual_grade_proportion == 0.4f) {
        printf("test_findGradeByStudentID passed\n");
    } else {
        printf("test_findGradeByStudentID failed\n");
    }

    found = findGradeByStudentID(head, "2023003");
    if (found == NULL) {
        printf("test_findGradeByStudentID (not found) passed\n");
    } else {
        printf("test_findGradeByStudentID (not found) failed\n");
    }

    freeGrades(&head);
}

int main(void) {
    test_addGrade();
    test_loadGradesFromFile();
    test_findGradeByStudentID();
    return 0;
}
