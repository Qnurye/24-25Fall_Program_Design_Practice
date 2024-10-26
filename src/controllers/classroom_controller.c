#include "controllers/classroom_controller.h"

void freeAvailableLessons(AvailableLessons *availableLessons) {
    if (availableLessons != NULL) {
        free(availableLessons);
    }
}

AvailableLessons *queryClassroomAvailableTime(char *classroomName, Classroom *classrooms, CourseSchedule *schedules) {
    AvailableLessons *availableLessons = (AvailableLessons *)malloc(sizeof(AvailableLessons));
    if (availableLessons == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    *availableLessons = (AvailableLessons){{{1}}};
    Classroom *classroom = findClassroomByName(classrooms, classroomName);
    if (classroom == NULL) {
        printf("未找到教室\n");
        freeAvailableLessons(availableLessons);
        return NULL;
    }

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j <= MAX_PERIODS - 1; j++) {
            availableLessons->lessons[i][j] = 1;
            for (CourseSchedule *p = schedules; p != NULL; p = p->next) {
                if (p->classroom_id == classroom->id && (int)p->day_of_week == i &&
                j >= p->start_lesson_id && j <= p->end_lesson_id) {
                    availableLessons->lessons[i][j] = 0;
                }
            }
        }
    }
    return availableLessons;
}

ClassroomAvailableTimeList *queryClassroomAvailableTimes(Classroom *classrooms, CourseSchedule *schedules) {
    ClassroomAvailableTimeList *list = (ClassroomAvailableTimeList *)malloc(sizeof(ClassroomAvailableTimeList));
    if (list == NULL) {
        printf("内存分配失败: ClassroomAvailableTimeList\n");
        return NULL;
    }
    list->count = 0;

    for (Classroom *p = classrooms; p != NULL; p = p->next) {
        AvailableLessons *availableLessons = queryClassroomAvailableTime(p->name, classrooms, schedules);
        if (availableLessons == NULL) {
            continue;
        }
        ClassroomAvailableTime availableTime = {p, *availableLessons};
        list->availableTimes[list->count++] = availableTime;

        freeAvailableLessons(availableLessons);
    }

    return list;
}
