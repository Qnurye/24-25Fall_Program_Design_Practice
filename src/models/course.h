//
// Created by qnurye on 24-9-10.
//

#ifndef VAR4_COURSE_H
#define VAR4_COURSE_H

// 课程结构体
typedef struct {
    int course_id;
    char course_name[100];
    char course_code[20];
    int credits;
    char department[100];
    int teacher_id;
} Course;

// 函数声明
Course *
create_course(const char *course_name, const char *course_code, int credits, const char *department, int teacher_id);

void free_course(Course *course);

int save_course(Course *course);

Course *get_course_by_id(int course_id);

int update_course(Course *course);

int delete_course(int course_id);

#endif //VAR4_COURSE_H
