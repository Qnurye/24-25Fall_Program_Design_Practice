#ifndef VAR4_COURSE_SELECTION_CONTROLLER_H
#define VAR4_COURSE_SELECTION_CONTROLLER_H

typedef struct {
    int success;
    char *message;
} CourseSelectionResult;

CourseSelectionResult *select_course(int student_id, int course_id);

void free_course_selection_result(CourseSelectionResult *result);


#endif // VAR4_COURSE_SELECTION_CONTROLLER_H
