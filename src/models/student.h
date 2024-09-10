//
// Created by qnurye on 24-9-10.
//

#ifndef VAR4_STUDENT_H
#define VAR4_STUDENT_H

typedef struct {
    int student_id;
    int user_id;
    int class_id;
} Student;

// 函数声明
Student *create_student(int user_id, int class_id);

void free_student(Student *student);

int save_student(Student *student);

Student *get_student_by_id(int student_id);

int update_student(Student *student);

int delete_student(int student_id);

#endif //VAR4_STUDENT_H
