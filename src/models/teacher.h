//
// Created by qnurye on 24-9-10.
//

#ifndef VAR4_TEACHER_H
#define VAR4_TEACHER_H

typedef struct {
    int teacher_id;
    int user_id;
    char department[100];
    char title[50];
} Teacher;

Teacher *create_teacher(int user_id, const char *department, const char *title);

void free_teacher(Teacher *teacher);

int save_teacher(Teacher *teacher);

Teacher *get_teacher_by_id(int teacher_id);

int update_teacher(Teacher *teacher);

int delete_teacher(int teacher_id);

#endif //VAR4_TEACHER_H
