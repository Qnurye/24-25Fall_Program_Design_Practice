#ifndef GRADE_H
#define GRADE_H

typedef struct Grade {
    char student_id[20];
    char course_name[50];
    int usual_grade;                // 平时分
    int final_grade;                // 期末分
    float usual_grade_proportion;   // 平时分占比
    struct Grade *next;
} Grade;

// 加载成绩数据
Grade *loadGradesFromFile(const char *filename);

// 保存成绩数据
void saveGradesToFile(Grade *head, const char *filename);

// 添加新的成绩
void addGrade(Grade **head, const char *student_id, const char *course_name, int usual_grade, int final_grade,
              float usual_grade_proportion);

// 根据学生ID查找成绩
Grade *findGradeByStudentID(Grade *head, const char *student_id);

// 释放成绩链表
void freeGrades(Grade **head);

// 获取指定学生的所有成绩
Grade *getAllGradesByStudentID(Grade *head, const char *student_id);

#endif // GRADE_H
