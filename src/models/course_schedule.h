//
// Created by qnurye on 24-9-10.
//

#ifndef VAR4_COURSE_SCHEDULE_H
#define VAR4_COURSE_SCHEDULE_H

// 课程安排结构体
typedef struct {
    int schedule_id;
    int course_id;
    int classroom_id;
    char classroom[50];
    char day_of_week[10];
    int start_lesson_id;
    int end_lesson_id;
} CourseSchedule;

// 函数声明
CourseSchedule *create_course_schedule(int course_id, int classroom_id, const char *classroom, const char *day_of_week,
                                       int start_lesson_id, int end_lesson_id);

void free_course_schedule(CourseSchedule *schedule);

int save_course_schedule(CourseSchedule *schedule);

CourseSchedule *get_course_schedule_by_id(int schedule_id);

int update_course_schedule(CourseSchedule *schedule);

int delete_course_schedule(int schedule_id);

#endif //VAR4_COURSE_SCHEDULE_H
