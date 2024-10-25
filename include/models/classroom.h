#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "timetable.h"

#define MAX_CLASSROOMS 100

typedef struct Classroom {
    int id;
    char name[50];
    int capacity;
    struct Classroom *next;
} Classroom;

typedef struct AvailableLessons {
    int lessons[7][MAX_PERIODS];
} AvailableLessons;

typedef struct ClassroomAvailableTime {
    Classroom *classroom;
    AvailableLessons availableLessons;
} ClassroomAvailableTime;

typedef struct ClassroomAvailableTimeList {
    ClassroomAvailableTime availableTimes[MAX_CLASSROOMS];
    int count;
} ClassroomAvailableTimeList;

// 加载教室数据
Classroom *loadClassroomsFromFile(const char *filename);

// 保存教室数据
void saveClassroomsToFile(Classroom *head, const char *filename);

// 添加新的教室
void addClassroom(Classroom **head, const char *name, int capacity);

// 根据教室名查找教室
Classroom *findClassroomByName(Classroom *head, const char *name);

// 释放教室链表
void freeClassrooms(Classroom **head);

// 根据教室ID查找教室
Classroom *findClassroomById(Classroom *head, int id);

#endif // CLASSROOM_H
