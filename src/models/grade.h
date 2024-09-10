//
// Created by qnurye on 24-9-10.
//

#ifndef VAR4_GRADE_H
#define VAR4_GRADE_H

typedef struct {
    int grade_id;
    int student_id;
    int course_id;
    double regular_grade;
    double final_grade;
    double regular_percentage;
    char graded_at[20];
} Grade;

Grade *create_grade(int student_id, int course_id, double regular_grade, double final_grade, double regular_percentage);

void free_grade(Grade *grade);

int save_grade(Grade *grade);

Grade *get_grade_by_id(int grade_id);

int update_grade(Grade *grade);

int delete_grade(int grade_id);

#endif //VAR4_GRADE_H
