//
// Created by qnurye on 24-9-10.
//

#ifndef VAR4_CLASSROOM_H
#define VAR4_CLASSROOM_H

// 教室结构体
typedef struct {
    int classroom_id;
    char classroom_name[50];
    int capacity;
    int is_available;
} Classroom;

// 函数声明
Classroom *create_classroom(const char *classroom_name, int capacity, int is_available);

void free_classroom(Classroom *classroom);

int save_classroom(Classroom *classroom);

Classroom *get_classroom_by_id(int classroom_id);

int update_classroom(Classroom *classroom);

int delete_classroom(int classroom_id);

#endif //VAR4_CLASSROOM_H
